#ifndef RAYTRACER_INTEGRATOR_H
#define RAYTRACER_INTEGRATOR_H

#include <HLSL.h>

namespace Raytracer
{
	class Ray;
	struct Sample;

	namespace Scenes
	{
		class Scene;
	}

	/**
	 * Implemented by classes that can calculate the visible color seen by a ray.
	 */
	class IIntegrator
	{
	public:
		/**
		 * Calculates the visible color seen via a given ray in a given scene.
		 *
		 * @param ray A ray
		 * @param scene A scene
		 * @return The color seen via \a ray in \a scene
		 */
		virtual float3 GetColor(Ray &ray, const Scenes::Scene &scene) = 0;
	};
}

#endif // RAYTRACER_INTEGRATOR_H
