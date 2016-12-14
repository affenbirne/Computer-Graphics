#include <stdio.h>
#include <time.h>
#include <string.h>

#include <vector>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp> 

#include <Raytracer/Raytracer.h>
#include <Rasterizer/SimpleRasterizer.h>

#include <Windowing/DisplayWindow.h>

using namespace glm;
using namespace Rasterizer;
using namespace Raytracer;
using namespace Raytracer::Scenes;
using namespace Raytracer::Objects;
using namespace Windowing;

/**
 * Creates a transformation matrix for a rotation around the x axis.
 *
 * @param a The rotation angle in degrees
 */
mat4x4 RotationX(float a)
{
	return rotate(mat4x4(1.0f), a, vec3(1.0f, 0.0f, 0.0f));
}

/**
 * Creates a transformation matrix for a rotation around the y axis.
 *
 * @param a The rotation angle in degrees
 */
mat4x4 RotationY(float a)
{
	return rotate(mat4x4(1.0f), a, vec3(0.0f, 1.0f, 0.0f));
}

/**
 * Creates a transformation matrix for a rotation around the z axis.
 *
 * @param a The rotation angle in degrees
 */
mat4x4 RotationZ(float a)
{
	return rotate(mat4x4(1.0f), a, vec3(0.0f, 0.0f, 1.0f));
}

/**
 * Creates a scene with a mesh, two lights, and a camera.
 *
 * @param fileName The file name of the mesh file. If this is NULL, BuildScene() creates just a
 *   single triangle for test purposes.
 * @param aspect The image aspect ratio to use for the scene's camera
 * @param mesh Receives a pointer to the central mesh object of the scene.
 * @return The created scene or NULL if an error occurred
 */
Scene *BuildScene(const char *fileName, float aspect, Mesh *&mesh)
{
	// Create the scene.
	Scene *scene = new Scene();
	if (scene == NULL)
		return NULL;

	// Create a triangle mesh.
	mesh = new Mesh();
	if (mesh == NULL)
	{
		delete scene;
		return NULL;
	}

	if (fileName == NULL)
	{
		// Create just a single triangle in the xz plane as test geometry.

		Triangle t;
		t.SetVertex(0, vec3(0, 0, 1.0f), vec3(0, 0, 1), vec3(1, 0, 0));
		t.SetVertex(1, vec3(1.0f, 0, -1.0f), vec3(0, 0, 1), vec3(0, 1, 0));
		t.SetVertex(2, vec3(-1.0f, 0, -1.0f), vec3(0, 0, 1), vec3(0, 0, 1));
		mesh->AddTriangle(t);
	}
	else
	{
		// Load the mesh from this file.
		if (!mesh->Load(fileName))
		{
			delete scene;
			mesh = NULL;
			return NULL;
		}
	}

	scene->AddChild(mesh);

	// Create two lights.
	Light *light = new PointLight(vec3(20.0f));
	if (light == NULL)
	{
		delete scene;
		mesh = NULL;
		return NULL;
	}

	light->SetPosition(vec3(-5.0f, 3.0f, 2.0f));
	scene->AddChild(light);

	light = new PointLight(vec3(3.0f, 3.0f, 4.0f));
	if (light == NULL)
	{
		delete scene;
		mesh = NULL;
		return NULL;
	}

	light->SetPosition(vec3(5.0f, -2.0f, -10.0f));
	scene->AddChild(light);

	// Create a camera.
	Camera *camera = new Camera(vec3(2.0f, 0.0f, 4.0f), vec3(0.0f, 0.0f, 0.0f), 
		vec3(0.0f, 1.0f, 0.0f), Camera::DefaultFov, aspect, 1.0f, 10.0f);
	if (camera == NULL)
	{
		delete scene;
		mesh = NULL;
		return NULL;
	}
	scene->AddChild(camera);
	scene->SetActiveCamera(camera);

	return scene;
}

/**
 * Renders the scene continuously into a window.
 *
 * @param width The image width
 * @param height The image height
 * @param rotate whether to rotate the geometry
 * @param filename the filename of a geometry to load.
 */
void Render(int width, int height, bool rotate, const char *filename)
{
	if (width <= 0 || height <= 0)
		return;

	Mesh *mesh;

	Scene *scene = BuildScene(filename, (float)width / height, mesh);

	if (scene == NULL)
	{
		// The mesh file could not be found or read or we ran out of memory.
		puts("Die Szene konnte nicht erstellt werden.");
		return;
	}

	SimpleRasterizer rasterizer;

	Image image(width, height);
	DisplayWindow window(width, height);
	window.SetImage(&image);

	// Keep rendering the scene into the window until the window is closed.
	while (window.ProcessMessages())
	{
		// Rotate the mesh over time.
		float t = 0.0f;
		if (rotate)
			t = window.GetTime();
		mesh->SetTransformation(RotationY(t * 36.0f) * RotationX(-90.0f));

		rasterizer.Render(image, *scene);
		window.Update();
	}

	delete scene;
}

/**
 * The main program
 */
int main(int argc, char *argv[])
{
	// Set this to true to have the geometry rotate by default.
	bool rotate = true;

	// Set this to false to use just a single triangle by default, 
  // or to true to load a more complex geometry.
	bool loadFile = true;

  // Set this to NULL to use just a single triangle to default,
  // or to a filename to load a more complex geometry.
  const char *filename = "data/kopf_subdivided.raw";

  for (int i = 1; ((i < argc) && (i < 3)); ++i)
  {
    if (strcmp(argv[i], "-rotate") == 0)
      rotate = true;
    else if (strcmp(argv[i], "-norotate") == 0)
      rotate = false;
    else if (strcmp(argv[i], "-nogeometry") == 0)
      filename = NULL;
    else
      filename = argv[i];
  }

	Render(512, 512, rotate, filename);
	return 0;
}
