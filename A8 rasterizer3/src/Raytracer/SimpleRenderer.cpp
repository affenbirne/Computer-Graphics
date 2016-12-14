#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

void SimpleRenderer::RenderImage(const Camera &camera, Image *image) const
{
	int w = image->GetWidth();
	int h = image->GetHeight();

	for (int y = 0; y < h; y++)
	{
		float fy = (float)y / h;
		for (int x = 0; x < w; x++)
			image->SetPixel(x, y, RenderPixel(camera, (float)x / w, fy));
	}
}
