#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

Scene::Scene(IIntegrator *surfaceIntegrator, IAccelerator *accelerator)
{
	this->surfaceIntegrator = surfaceIntegrator;
	this->accelerator = accelerator;

	updateAccelerator = true;

	objects.clear();
	lights.clear();
}

void Scene::AddLight(ILight *light)
{
	if (light != NULL)
		lights.push_back(light);
}

void Scene::AddObject(IPrimitive *object)
{
	if (object != NULL)
	{
		objects.push_back(object);
		updateAccelerator = true;
	}
}

const IAccelerator *Scene::GetAccelerator() const
{
	return accelerator;
}

const std::vector<ILight *> Scene::GetLights() const
{
	return lights;
}

const std::vector<IPrimitive *> Scene::GetObjects() const
{
	return objects;
}

float3 Scene::Shade(Ray &ray)
{
	if (updateAccelerator && accelerator != NULL)
	{
		accelerator->Init(*this);
		updateAccelerator = false;
	}

	return surfaceIntegrator->GetColor(ray, *this);
}
