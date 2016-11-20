#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

float3 Renderer::RenderPixel(Scene &scene, const Camera &camera, int x, int y) const
{
	Ray ray;
	camera.SpawnRay((float)x, (float)y, ray);
	return scene.Shade(ray);
}
