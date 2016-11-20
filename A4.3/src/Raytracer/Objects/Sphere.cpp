#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;
using namespace Raytracer::Objects;

Sphere::Sphere(const float3 &center, float radius)
{
	this->center = center;
	this->radius = radius;
	this->radius2 = radius * radius;
	this->material = NULL;
}

Sphere::Sphere(const float3 &center, float radius, Material *material)
{
	this->center = center;
	this->radius = radius;
	this->radius2 = radius * radius;
	this->material = material;
}

void Sphere::GetExtent(float3 &min, float3 &max) const
{
	min = center - radius;
	max = center + radius;
};

void Sphere::GetIntersection(const Ray &ray, float distance, Intersection &intersection) const
{
	intersection.position = ray.GetOrigin() + ray.GetDirection() * distance;
	intersection.material = this->material;
	intersection.normal = normalize(intersection.position - center);
}

bool Sphere::HitTest(const Ray &ray, RayHit &hit) const
{
	hit.Set(&ray, 0, NULL);
	// Equation: Vt^2 + Dt + |OC|^2  =  R^2
	float V = length(ray.GetDirection());
	V *= V;
	float3 OC = ray.GetOrigin() - center;
	float D = 2.0f * dot(OC, ray.GetDirection());

	if (V == 0) {
		// no quadratic equation
		if (D != 0) {
			float dist = length(OC);
			dist = (radius2 - dist*dist) / D;
			if (dist > 0) {
				hit.Set(&ray, dist, this);
				return true;
			}
		}
		// else: no linear equation either
	}
	else {
		// quadratic equation
		if (D == 0) {
			// no linear part
			float dist = length(OC);
			dist = (radius2 - dist*dist);
			if (dist < 0) {
				// no real solution
				return false;
			}
			dist = sqrt(dist / V);
			// only positive value of interest
			hit.Set(&ray, dist, this);
		}
		else {
			float d1, d2;
			float DV = 0.5f * D / V;
			float sq = length(OC);
			sq = DV*DV + (radius2 - sq*sq) / V;
			if (sq < 0.0f) {
				// no real solution
				return false;
			}
			sq = sqrt(sq);
			d1 = -DV + sq;
			d2 = -DV - sq;
			if (d1 < d2) {
				if (d1 > 0)
					hit.Set(&ray, d1, this);
			}
			else {
				if (d2 > 0)
					hit.Set(&ray, d2, this);
			}
		}
		return true;
	}
	
return false;
}
