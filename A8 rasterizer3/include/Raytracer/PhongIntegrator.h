#ifndef RAYTRACER_PHONGINTEGRATOR_H
#define RAYTRACER_PHONGINTEGRATOR_H

#include <glm.hpp>

#include <Raytracer/IIntegrator.h>

namespace Raytracer
{
	namespace Scenes
	{
		class Scene;
	}

	/**
	 * Calculates the visible color seen by a ray using the Phong illumination model.
	 */
	class PhongIntegrator : public IIntegrator
	{
	private:
		/**
		 * The background color seen by rays that exit the scene
		 */
		glm::vec3 backgroundColor;

	public:
		/**
		 * Constructs a new PhongIntegrator object.
		 */
		PhongIntegrator();

		glm::vec3 GetColor(Ray &ray, const Accelerator &accelerator);
	};
}

#endif // RAYTRACER_PHONGINTEGRATOR_H
