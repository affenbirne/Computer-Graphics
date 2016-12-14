#ifndef RAYTRACER_INTEGRATOR_H
#define RAYTRACER_INTEGRATOR_H

#include <glm.hpp>

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
		 * Calculates the visible color seen via a given ray in a scene.
		 *
		 * @param ray A ray
		 * @param accelerator An Accelerator object that can be used to trace rays through the
		 *   scene
		 * @return The color seen via \a ray in \a scene
		 */
		virtual glm::vec3 GetColor(Ray &ray, const Accelerator &accelerator) = 0;
	};
}

#endif // RAYTRACER_INTEGRATOR_H
