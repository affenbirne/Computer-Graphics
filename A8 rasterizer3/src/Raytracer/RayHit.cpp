#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;

Raytracer::RayHit::RayHit()
{
	Set(0, NULL);
}

Raytracer::RayHit::RayHit(const Ray &ray)
{
	Set(ray, 0, NULL);
}

Raytracer::RayHit::RayHit(const Ray &ray, float distance, const Scenes::PhysicalObject *object)
{
	Set(ray, distance, object);
}

float Raytracer::RayHit::GetDistance() const
{
	if (object == NULL)
		return 0;
	return distance;
}

bool Raytracer::RayHit::GetIntersection(Intersection &intersection)
{
	if (object == NULL)
		return false;

	object->GetIntersection(*this, intersection);
	return true;
}

const vec3 Raytracer::RayHit::GetPosition() const
{
	return ray.GetOrigin() + ray.GetDirection() * distance;
}

const Scenes::PhysicalObject *RayHit::GetObject() const
{
	return object;
}

const Ray &RayHit::GetRay() const
{
	return ray;
}

void RayHit::Set(float distance, const Scenes::PhysicalObject *object)
{
	this->object = object;
	if (object != NULL)
		this->distance = distance;
	else
		this->distance = 0;
}

void RayHit::Set(const Ray &ray, float distance, const Scenes::PhysicalObject *object)
{
	this->ray = ray;
	Set(distance, object);
}

void RayHit::SetRay(const Ray &ray)
{
	this->ray = ray;
}
