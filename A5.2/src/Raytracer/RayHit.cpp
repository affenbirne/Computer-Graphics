#include <Raytracer/Raytracer.h>

using namespace Raytracer;

Raytracer::RayHit::RayHit()
{
	this->ray = NULL;
	this->distance = 0;
	this->object = NULL;
}

Raytracer::RayHit::RayHit(const Ray *ray)
{
	this->ray = ray;
	this->distance = 0;
	this->object = NULL;
}

Raytracer::RayHit::RayHit(const Ray *ray, float distance, const Scenes::IPrimitive *object)
{
	this->ray = ray;
	this->distance = distance;
	this->object = object;
}

Raytracer::RayHit::RayHit(RayHit &hit)
{
	this->ray = hit.ray;
	this->distance = hit.distance;
	this->object = hit.object;
}

float Raytracer::RayHit::GetDistance() const
{
	if (object == NULL)
		return 0;
	return distance;
}

bool Raytracer::RayHit::GetIntersection(Intersection &intersection)
{
	if (ray == NULL || object == NULL)
		return false;

	object->GetIntersection(*ray, distance, intersection);
	return true;
}

const Scenes::IPrimitive * Raytracer::RayHit::GetObject() const
{
	return object;
}

const Ray * Raytracer::RayHit::GetRay() const
{
	return ray;
}

void Raytracer::RayHit::Set(float distance, const Scenes::IPrimitive *object)
{
	this->object = object;
	if (object != NULL)
		this->distance = distance;
	else
		this->distance = 0;
}

void Raytracer::RayHit::Set(const Ray *ray, float distance, const Scenes::IPrimitive *object)
{
	this->ray = ray;
	Set(distance, object);
}

void Raytracer::RayHit::SetRay(const Ray *ray)
{
	this->ray = ray;
}
