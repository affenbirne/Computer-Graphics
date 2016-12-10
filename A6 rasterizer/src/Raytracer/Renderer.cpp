#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;
using namespace Raytracer::Scenes;

Renderer::Renderer()
{
	accelerator = NULL;
	integrator = NULL;
}

Renderer::~Renderer()
{
	delete accelerator;
	delete integrator;
}

vec3 Renderer::RenderPixel(const Camera &camera, float x, float y) const
{
	Ray ray;
	camera.SpawnRay(x, y, ray);
	return integrator->GetColor(ray, *accelerator);
}

IIntegrator *Renderer::GetIntegrator() const
{
	return integrator;
}

void Renderer::SetIntegrator(IIntegrator *integrator)
{
	delete this->integrator;
	this->integrator = integrator;
}

Accelerator *Raytracer::Renderer::GetAccelerator() const
{
	return accelerator;
}

void Raytracer::Renderer::SetAccelerator(Accelerator *accelerator)
{
	delete this->accelerator;
	this->accelerator = accelerator;
}

Image *Renderer::Render(const Scenes::Scene &scene, int width, int height)
{
	Camera *camera = scene.GetActiveCamera();

	if (camera == NULL || accelerator == NULL || integrator == NULL || width <= 0 || height <= 0)
		return NULL;

	Image *image = new Image(width, height);
	if (image == NULL)
		return NULL;

	accelerator->SetScene(&scene);

	RenderImage(*camera, image);

	return image;
}
