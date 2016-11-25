#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

PointLight::PointLight(const float3 &position, const float3 &intensity)
{
  this->position = position;
  this->intensity = intensity;
}

float3 PointLight::ComputeDirectContribution(const Intersection &intersection, const Scene &scene)
{
  // TODO: Implement the calculation of the diffuse and specular lighting according to the
  // Phong light modelat the point determined by the intersection calculation.
  // Also respect that the intensity of the light will decrease with increasing distance to the light source,
  // or by positioning them behind other objects (shadowing).

	float3 ambient = intersection.material->GetAmbient();
	float3 L = position - intersection.position;
	// factor for light distance attenuation
	float dist = (1.0f / (1.5f + 0.1f * length(L)));
	L = normalize(L);
	// pos + epsilon to avoid artefacts
	Ray *ray = new Ray(intersection.position + 0.001f * L, L);
	RayHit *rh = new RayHit();
	for (int i = 0; i < scene.GetObjects().size(); i++) {
		// if hit, then no direct light
		if (scene.GetObjects()[i]->HitTest(*ray, *rh))
			return ambient;
	}
	delete ray, rh;

	float3 diffuse = float3 (0, 0, 0);
	float3 specular = float3 (0, 0, 0);
	float3 I = dist*dist * intensity;
	float NdotL = dot(intersection.normal, L);

	if (NdotL > 0.0f) {
		diffuse = intersection.material->GetDiffuse() * NdotL;
		
		float3 R = 2.0f * intersection.normal * NdotL - L;
		float RdotV = dot(R, intersection.viewDirection);
		if (RdotV > 0.0f) {
			specular = intersection.material->GetSpecular();
			specular *= powf(RdotV, intersection.material->GetShininess());
		}
	}
	
	return ambient + (diffuse + specular) * I;
}
