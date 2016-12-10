#include <limits>

#define RAYTRACER_USE_FOREACH
#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

bool SimpleAccelerator::HitTest(const Ray &ray, RayHit *hit) const
{
	if (hit == NULL)
	{
		// Search for any intersection.
		foreach_c (PhysicalObject *, object, physicalObjects)
		{
			Ray objectRay = ray.Transform((*object)->GetGlobalToLocal());
			if ((*object)->HitTest(objectRay, NULL))
				return true;
		}

		return false;
	}
	else
	{
		// Search for the closest intersection.
		hit->Set(ray, 0, NULL);

		foreach_c (PhysicalObject *, object, physicalObjects)
		{
			Ray objectRay = ray.Transform((*object)->GetGlobalToLocal());
			RayHit objectHit;
			if ((*object)->HitTest(objectRay, &objectHit) &&
				(hit->GetObject() == NULL || objectHit.GetDistance() < hit->GetDistance()))
			{
				*hit = objectHit;
			}
		}

		return (hit->GetObject() != NULL);
	}
}

void Raytracer::SimpleAccelerator::SetScene(const Scenes::Scene *scene)
{
	this->scene = scene;
	physicalObjects.clear();
	lights.clear();

	if (scene == NULL)
		return;

	AddObject(scene);
}

void Raytracer::SimpleAccelerator::AddObject(const SceneObject *object)
{
	if (object->IsInstanceOf(SceneObjectType_PhysicalObject))
		physicalObjects.push_back((PhysicalObject *)object);

	if (object->IsInstanceOf(SceneObjectType_Light))
		lights.push_back((Light *)object);

	foreach_c (SceneObject *, child, object->GetChildren())
		AddObject(*child);
}

const std::vector<Light *> &SimpleAccelerator::GetLights() const
{
	return lights;
}
