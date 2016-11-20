#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

void SimpleRenderer::Render(Scene &scene, const Camera &camera, Image &image) const
{
	for (int y = 0; y < image.GetHeight(); y++)
	{
		for (int x = 0; x < image.GetWidth(); x++)
			image.SetPixel(x, y, RenderPixel(scene, camera, x, y));
	}
}
