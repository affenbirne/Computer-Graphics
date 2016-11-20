#include <limits>

#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

bool SimpleAccelerator::Cast(const Ray &ray, float maxDistance) const
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		RayHit hit;
		if (objects[i]->HitTest(ray, hit) && hit.GetDistance() <= maxDistance)
			return true;
	}

	return false;
}

void SimpleAccelerator::Init(const Scenes::Scene &scene)
{
	this->objects = scene.GetObjects();
}

bool SimpleAccelerator::Trace(const Ray &ray, RayHit &hit) const
{
	hit.Set(&ray, 0, NULL);

	for (unsigned int i = 0; i < objects.size(); i++)
	{
		RayHit objectHit;
		if (objects[i]->HitTest(ray, objectHit) &&
			(hit.GetObject() == NULL || objectHit.GetDistance() < hit.GetDistance()))
		{
			hit = objectHit;
		}
	}

	return (hit.GetObject() != NULL);
}
