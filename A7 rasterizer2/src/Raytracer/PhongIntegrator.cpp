#define RAYTRACER_USE_FOREACH
#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;
using namespace Raytracer::Scenes;

vec3 PhongIntegrator::GetColor(Ray &ray, const Accelerator &accelerator)
{
	// Trace the ray to find a RayHit for the closest intersecting object.
	RayHit hit;
	accelerator.HitTest(ray, &hit);
	
	Intersection intersection;
	if (!hit.GetIntersection(intersection))
	{
		// The ray does not intersect any object.
		return backgroundColor;
	}

	// Convert the intersection into world space.
	intersection = intersection.Transform(hit.GetObject()->GetGlobalTransformation());

	// The ray intersects an object. Determine the visible color at the intersection point.
	vec3 color(0, 0, 0);	

	// Sum the contribution of all lights in the scene.
	foreach_c (Light *, light, accelerator.GetLights())
	{
		Intersection lightIntersection = intersection.Transform((*light)->GetGlobalToLocal());
		color += (*light)->ComputeDirectContribution(&accelerator, lightIntersection);
	}

	// If the object has a material, add its ambient color.
	if (intersection.material != NULL)
		color += intersection.material->GetAmbient();

	return color;
}

Raytracer::PhongIntegrator::PhongIntegrator()
{
	backgroundColor = vec3(0, 0, 0);
}
