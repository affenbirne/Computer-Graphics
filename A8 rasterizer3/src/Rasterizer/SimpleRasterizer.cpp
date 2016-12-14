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

void SimpleRasterizer::SortVertices(const Triangle &t, int &minIndex, int &middleIndex,
  int &maxIndex)
{
  // Since the number of possible cases is limited, it's probably quickest to just check them all
  // explicitly.
  if (t.position[1].y < t.position[0].y)
  {
    // y1 < y0
    if (t.position[1].y < t.position[2].y)
    {
      // y1 < y0 && y1 < y2
      minIndex = 1;
      if (t.position[0].y < t.position[2].y)
        maxIndex = 2;
      else
        maxIndex = 0;
    }
    else
    {
      // y2 <= y1 < y0
      minIndex = 2;
      maxIndex = 0;
    }
  }
  else
  {
    // y0 <= y1
    if (t.position[1].y < t.position[2].y)
    {
      // y0 <= y1 < y2
      minIndex = 0;
      maxIndex = 2;
    }
    else
    {
      // y0 <= y1 && y2 <= y1
      maxIndex = 1;
      if (t.position[0].y < t.position[2].y)
        minIndex = 0;
      else
        minIndex = 2;
    }
  }
  middleIndex = 3 - minIndex - maxIndex;
}

void SimpleRasterizer::DrawSpan(int x1, int x2, int y, float z1, float z2, vec3 &color1,
                vec3 &color2)
{
  if (y < 0 || y >= image->GetHeight())
    return;

  if (x2 < x1)
  {
    DrawSpan(x2, x1, y, z2, z1, color2, color1);
    return;
  }

  int dx = x2 - x1;
  if (dx == 0)
    return;

  vec3 dc = (color2 - color1) * (1.0f / dx);
  vec3 c = color1;

  // z-buffer
  double dz = (z2 - z1) * (1.0 / dx); // more precise
  float z = z1;

  for (int x = x1; x < x2; x++)
  {
    if (x >= 0 && x < image->GetWidth())
    {
		// check if pixel is in front of so far drawn
		if (z < zBuffer[y*image->GetWidth() + x]) {
			image->SetPixel(x, y, c);
			zBuffer[y*image->GetWidth() + x] = z;
		}
    }
    c += dc;
	z += dz;
  }
}

void SimpleRasterizer::DrawTriangle(const Triangle &t)
{
  // Sort the vertices according to their y coordinate. The vertex minIndex will have the lowest
  // y value, the vertex maxIndex the highest.
  int minIndex, middleIndex, maxIndex;
  SortVertices(t, minIndex, middleIndex, maxIndex);
  float minY = t.position[minIndex].y;
  float middleY = t.position[middleIndex].y;
  float maxY = t.position[maxIndex].y;

  int y0 = (int)minY;
  int y1 = (int)middleY;
  int y2 = (int)maxY;

  if (y2 <= y0)
    return;

  float x0 = t.position[minIndex].x;
  float z0 = t.position[minIndex].z; // z-buffer
  vec3 color0 = t.color[minIndex];

  float dy = maxY - minY;
  float dx0 = (t.position[maxIndex].x - x0) / dy;
  double dz0 = (t.position[maxIndex].z - z0) / dy; // z-buffer
  vec3 dc0 = (t.color[maxIndex] - color0) / dy;
  
  if (y1 > y0)
  {
    float x1 = x0;
	float z1 = z0; // z-buffer
    vec3 color1 = color0;

    dy = middleY - minY;
    float dx1 = (t.position[middleIndex].x - x1) / dy;
	double dz1 = (t.position[middleIndex].z - z1) / dy; // z-buffer
    vec3 dc1 = (t.color[middleIndex] - color1) * (1.0f / dy);


    for (int y = y0; y < y1; y++)
    {
      DrawSpan((int)x0, (int)x1, y, z0, z1, color0, color1);
      x0 += dx0;
      x1 += dx1;
	  z0 += dz0; // z-buffer
	  z1 += dz1; // z-buffer
      color0 += dc0;
      color1 += dc1;
    }
  }

  if (y2 > y1)
  {
    float x1 = t.position[middleIndex].x;
	float z1 = t.position[middleIndex].z; // z-buffer
    vec3 color1 = t.color[middleIndex];

    float dy = maxY - middleY;
	float dx1 = (t.position[maxIndex].x - x1) / dy;
	float dz1 = (t.position[maxIndex].z - z1) / dy; // z-buffer
    vec3 dc1 = (t.color[maxIndex] - color1) * (1.0f / dy);


    for (int y = y1; y < y2; y++)
    {
      DrawSpan((int)x0, (int)x1, y, z0, z1, color0, color1);
      x0 += dx0;
      x1 += dx1;
	  z0 += dz0; // z-buffer
	  z1 += dz1; // z-buffer
      color0 += dc0;
      color1 += dc1;
    }
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

  //TODO: Painter's Algorithm
  SortTriangles(renderTriangles);
  // Draw the triangles in the right order!
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
