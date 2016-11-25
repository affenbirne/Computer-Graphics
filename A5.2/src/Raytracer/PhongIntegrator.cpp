#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

float3 PhongIntegrator::GetColor(Ray &ray, const Scene &scene)
{
	if (scene.GetAccelerator() == NULL)
		return float3(0, 0, 0);

	// Trace the ray to find a RayHit for the closest intersecting object.
	RayHit hit;
	scene.GetAccelerator()->Trace(ray, hit);
	
	Intersection intersection;
	if (!hit.GetIntersection(intersection))
	{
		// The ray does not intersect any object.
		return backgroundColor;
	}

	// The ray intersects an object. Determine the visible color at the intersection point.
	float3 color(0, 0, 0);	

	// Sum the contribution of all lights in the scene.
	for (unsigned int i = 0; i < scene.GetLights().size(); i++)
		color += scene.GetLights()[i]->ComputeDirectContribution(intersection, scene);

	// If the object has a material, add its ambient color.
	if (intersection.material != NULL)
		color += intersection.material->GetAmbient();

	return color;
}

Raytracer::PhongIntegrator::PhongIntegrator()
{
	backgroundColor = float3(0, 0, 0);
}
