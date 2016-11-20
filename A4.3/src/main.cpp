#include <stdio.h>

#include <vector>

#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;
using namespace Raytracer::Objects;

/**
 * Places a few spheres in the scene and adds some lights.
 *
 * @param scene The scene
 */
void BuildScene(Scene &scene)
{
	const int sphereCount = 6;

	Material *material;

	float3 colors[sphereCount] =
	{
		float3(1.0f, 0.0f, 0.0f),
		float3(1.0f, 1.0f, 0.0f),
		float3(0.0f, 1.0f, 0.0f),
		float3(0.0f, 1.0f, 1.0f),
		float3(0.0f, 0.0f, 1.0f),
		float3(1.0f, 0.0f, 1.0f)
	};

	for (int i = 0; i < sphereCount; i++)
	{
		material = new Material();

		float3 ambient = colors[i] * 0.01f;
		material->SetAmbient(ambient);
		material->SetDiffuse(colors[i]);
		material->SetShininess(25.0f);

		float x = (float)(sin(i * (HLSL_EX_PI / 3.0)) * 5.0);
		float y = (float)(cos(i * (HLSL_EX_PI / 3.0)) * 5.0);

		scene.AddObject(new Sphere(float3(x, y, 0), 2.0f, material));
	}

	// scene.AddLight(new PointLight(float3(-15.0f, 15.0f, 20.0f), 40.0f));
	// scene.AddLight(new PointLight(float3(0, 0, 0), 4.0f));
}

/**
 * Renders the scene and saves the result to a BMP file.
 *
 * @param fileName The name of the file
 * @param width The image width
 * @param height The image height
 */
void Render(const char *fileName, int width, int height)
{
	if (fileName == NULL || width <= 0 || height <= 0)
		return;

	Image image(width, height);
	Scene scene(new SimpleIntegrator(), new SimpleAccelerator());
	Camera camera(width, height,
		float3(0.0f, 0.0f, 15.0f), 
		float3(0.0f, 0.0f, 0.0f), 
		float3(0.0f, 1.0f, 0.0f), 
		53.13f);
	SimpleRenderer renderer;

	BuildScene(scene);

	puts("Rendere Bild...");
	image.Clear(float3(0.0f, 0.0f, 0.0f));
	renderer.Render(scene, camera, image);

	puts("Speichere Ergebnis...");
	image.SaveBMP(fileName, 2.2f);
}

/**
 * The main program
 */
int main()
{
	Render("image.bmp", 512, 512);
	return 0;
}
