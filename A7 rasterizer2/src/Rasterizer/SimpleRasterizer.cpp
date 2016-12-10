#include <algorithm>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/matrix_inverse.hpp>

#define RAYTRACER_USE_FOREACH
#include <Raytracer/Raytracer.h>

#include <Rasterizer/SimpleRasterizer.h>

using namespace std;
using namespace glm;
using namespace Rasterizer;
using namespace Raytracer;
using namespace Raytracer::Objects;
using namespace Raytracer::Scenes;

SimpleRasterizer::SimpleRasterizer()
{
  ambientLight = vec3(0.01f);
}

bool SimpleRasterizer::CompareTriangle(const Triangle &t1, const Triangle &t2)
{
  // These aren't actually the mean values, but since both are off by a constant factor (3),
  // this inequation is equivalent.
  return (t1.position[0].z + t1.position[1].z + t1.position[2].z >
    t2.position[0].z + t2.position[1].z + t2.position[2].z);
}


void SimpleRasterizer::DrawSpan(int x1, int x2, int y, float z1, float z2, vec3 &color1,
                vec3 &color2)
{
	int direction = 1; // x1 < x2
	int offset = 0; // for not filling far right pixels
	// Clipping
	if (y < 0 || y > image->GetHeight()) return; // not in image
	if (x1 <= x2) {
		if (x1 < 0) x1 = 0;
		if (x2 > image->GetWidth()) x2 = image->GetWidth();
	} else {
		if (x2 < 0) x2 = 0;
		if (x1 > image->GetWidth()) x1 = image->GetWidth();
		direction = -1;
		offset = -1;
	}

	int abs = x2 - x1;
	for (int i = offset; i != abs + offset; i += direction) {
		float t = (float) i / abs;
		// TODO: Gouraud Shading / [z-buffer]
		image->SetPixel(x1 + i, y, t * color1 + (1.0f - t) * color2);
	}
}

void SimpleRasterizer::DrawTriangle(const Triangle &t)
{
	int top_i = 0, bottom_i = 2;
	for (int i = 0; i < 3; i++) {
		if (t.position[i].y > t.position[top_i].y)
			top_i = i;
		if (t.position[i].y < t.position[bottom_i].y)
			bottom_i = i;
	}
	int middle_i = 3 - top_i - bottom_i;
	vec3 top = t.position[top_i];
	vec3 middle = t.position[middle_i];
	vec3 bottom = t.position[bottom_i];
	
	int y = (int)round(top.y);
	float x1 = top.x, x2 = top.x;
	
	// top to middle
	int abs = (int)round(top.y - bottom.y);
	int half = (int)round(top.y - middle.y);
	
	// TODO: Better would be Bresenhams Alg
	float delta_x1 = (half == 0) ? 0 : (middle.x - top.x) / half;
	float delta_x2 = (abs == 0) ? 0 : (bottom.x - top.x) / abs;
	int j = 0;
	// TODO: sth wrong, still infinity loop
	while (j <= abs) {
		for (int i = 0; i + j <= half; i++, j++, y--) {
			float u = (float) i / half;
			float v = (float) j / abs;
			DrawSpan((int)round(x1), (int)round(x2), y,
				(1.0f - u) * top.z + u * middle.z, (1.0f - v) * top.z + v * bottom.z,
				(1.0f - u) * t.color[top_i] + u * t.color[middle_i],
				(1.0f - v) * t.color[top_i] + v * t.color[bottom_i]);
			x1 += delta_x1;
			x2 += delta_x2;
		}
		// middle to bottom
		half = (int)round(middle.y - bottom.y);
		delta_x1 = (half == 0) ? 0 : (bottom.x - middle.x) / half;
	}
}

vec3 SimpleRasterizer::LightVertex(vec4 position, vec3 normal, vec3 color)
{
  vec3 result = color * ambientLight;

  foreach (const Light *, light, lights)
  {
    vec3 intensity = vec3(1.0f);
    if ((*light)->IsInstanceOf(SceneObjectType_PointLight))
      intensity = ((PointLight *)*light)->GetIntensity();

    vec3 distance = (*light)->GetPosition() - vec3(position);
    float attenuation = 1.0f / (0.001f + dot(distance, distance));
    vec3 direction = normalize(distance);

    float lambert = glm::max(0.0f, dot(normal, direction));

    if (lambert > 0)
      result += color * lambert * attenuation * intensity;
  }

  return result;
}


void SimpleRasterizer::SortTriangles(vector<Triangle> &triangles)
{
  sort(triangles.begin(), triangles.end(), CompareTriangle);
}


void SimpleRasterizer::TransformAndLightTriangle(Triangle &t, 
                                                 const mat4 &modelTransform,
                                                 const mat4 &modelTransformNormals)
{
  for (int i = 0; i < 3; i++)
  {
    vec4 worldPos = modelTransform * vec4(t.position[i], 1.0f);
    vec3 normal = normalize(vec3(modelTransformNormals * vec4(t.normal[i], 0.0f)));

    t.color[i] = LightVertex(worldPos, normal, t.color[i]);

    vec4 pos = viewProjectionTransform * worldPos;

    // Transform to screen coordinates
    t.position[i].x = (pos.x / pos.w * 0.5f + 0.5f) * image->GetWidth();
    t.position[i].y = (pos.y / pos.w * -0.5f + 0.5f) * image->GetHeight();
    t.position[i].z = pos.z / pos.w;
  }
}


void SimpleRasterizer::RenderMesh(const Mesh *mesh)
{
  if (mesh == NULL)
    return;

  // Compute the transformation from model to world space and its transposed inverse (for the
  // normals).
  glm::mat4 modelTransform = mesh->GetGlobalTransformation();
  glm::mat4 transposedInverseMT = inverseTranspose(modelTransform);

  // Transform and light all triangles in the mesh.
  const vector<Triangle> &meshTriangles = mesh->GetTriangles();
  vector<Triangle> renderTriangles;

  foreach_c(Triangle, triangle, meshTriangles)
  {
    Triangle t = *triangle;
    TransformAndLightTriangle(t, modelTransform, transposedInverseMT);
    renderTriangles.push_back(t);
  }

  //TODO bonus task: Painter's Algorithm
  // Draw the triangles.
  foreach(Triangle, triangle, renderTriangles)
    DrawTriangle(*triangle);
}

void SimpleRasterizer::ScanObject(const Raytracer::Scenes::SceneObject *object)
{
  if (object == NULL)
    return;

  if (object->IsInstanceOf(SceneObjectType_Light))
    lights.push_back((const Light *)object);
  if (object->IsInstanceOf(SceneObjectType_Mesh))
    meshes.push_back((const Mesh *)object);

  foreach_c(SceneObject *, child, object->GetChildren())
    ScanObject(*child);
}

bool SimpleRasterizer::Render(Image &image, const Scene &scene)
{
  image.Clear(vec3(0));

  Camera *camera = scene.GetActiveCamera();
  if (camera == NULL)
    return false;

  zBuffer = new float[image.GetWidth() * image.GetHeight()];
  for (int i = 0; i < image.GetWidth() * image.GetHeight(); i++)
    zBuffer[i] = 1.0f;

  // Build lists of all lights and meshes in the scene.
  lights.clear();
  meshes.clear();
  ScanObject(&scene);

  mat4 projectionTransform = perspective(camera->GetFov(),camera->GetAspect(), 
    camera->GetNearClip(), camera->GetFarClip());
  mat4 viewTransform = lookAt(camera->GetEye(), camera->GetLookAt(), camera->GetUp());
  viewProjectionTransform = projectionTransform * viewTransform;

  // Render all meshes we found.
  this->image = &image;
  foreach(const Mesh *, mesh, meshes)
    RenderMesh(*mesh);

  delete[] zBuffer;

  return true;
}
