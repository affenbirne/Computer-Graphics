#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;
using namespace Raytracer::Scenes;

PointLight::PointLight(const vec3 &intensity)
{
	this->intensity = intensity;
}

vec3 PointLight::ComputeDirectContribution(const Accelerator *accelerator,
											 const Intersection &intersection)
{
	vec3 c = vec3(0.0f);

	vec3 distance = -intersection.position;
	float attenuation = 1.0f / (0.001f + dot(distance, distance));
	vec3 direction = normalize(distance);

	float lambert = max(0.0f, dot(intersection.normal, direction));

	if (lambert > 0)
	{
		if (accelerator != NULL)
		{
			Ray shadowRay(intersection.position + direction * 0.001f, direction,
				length(distance) - 0.001f);

			if (accelerator->HitTest(shadowRay.Transform(GetGlobalTransformation()), NULL))
				return c;
		}

		c = intersection.material->GetDiffuse() * lambert * attenuation * intensity;

		if (all(greaterThan(intersection.material->GetSpecular(), vec3(0.0f))))
		{
			float specular = dot(intersection.viewDirection,
				reflect(-direction, intersection.normal));

			if (specular > 0) 
			{
				c += intersection.material->GetSpecular() *
					(powf(specular, intersection.material->GetShininess())) * attenuation *
					intensity;
			}
		}	
	}

	return c;
}

vec3 PointLight::GetIntensity() const
{
	return intensity;
}

bool PointLight::IsInstanceOf(SceneObjectType type) const
{
	return (type == SceneObjectType_PointLight || Light::IsInstanceOf(type));
}
