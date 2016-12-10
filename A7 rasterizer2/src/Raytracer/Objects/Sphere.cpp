#include <Raytracer/Raytracer.h>

using namespace glm;;
using namespace Raytracer;
using namespace Raytracer::Scenes;
using namespace Raytracer::Objects;

Sphere::Sphere(float radius) : PhysicalObject()
{
	this->radius = radius;
	this->radius2 = radius * radius;
	this->material = NULL;
}

Sphere::Sphere(float radius, Material *material) : PhysicalObject()
{
	this->radius = radius;
	this->radius2 = radius * radius;
	this->material = material;
}

void Sphere::GetIntersection(const RayHit &hit, Intersection &intersection) const
{
	intersection.position = hit.GetPosition();
	intersection.viewDirection = -hit.GetRay().GetDirection();
	intersection.normal = normalize(intersection.position);
	intersection.material = material;
}

bool Sphere::HitTest(const Ray &ray, RayHit *hit) const
{
	if (hit != NULL)
		hit->Set(ray, 0, NULL);

	vec3 distance = ray.GetOrigin();

	float a = dot(ray.GetDirection(), ray.GetDirection());
	float b = 2.0f * dot(ray.GetDirection(), distance);
	float c = dot(distance, distance) - radius2;

	float discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f)
		return false;

	float root = sqrtf(discriminant);
	float q;
	if (b < 0)
		q = (-b - root) / 2.0f;
	else
		q = (-b + root) / 2.0f;

	float t0 = q / a;
	float t1 = c / q;

	if (hit == NULL)
	{
		if (t0 < 0 && t1 < 0)
		{
			// Both intersections behind the ray origin.
			return false;
		}
		else if (t0 >= ray.GetLength() && t1 >= ray.GetLength())
		{
			// Both intersection beyond the ray end.
			return false;
		}

		// At least one intersection between ray origin and ray end.
		return true;
	}

	if (t0 > t1)
	{
		float t = t0;
		t0 = t1;
		t1 = t;
	}

	if (t1 < 0)
		return false;
	else if (t0 < 0)
		hit->Set(t1, this);
	else
		hit->Set(t0, this);

	return true;
}

bool Sphere::IsInstanceOf(SceneObjectType type) const
{
	return (type == SceneObjectType_Sphere || PhysicalObject::IsInstanceOf(type));
}
