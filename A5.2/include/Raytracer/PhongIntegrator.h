#ifndef RAYTRACER_PHONGINTEGRATOR_H
#define RAYTRACER_PHONGINTEGRATOR_H

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
		float3 backgroundColor;

	public:
		/**
		 * Constructs a new PhongIntegrator object.
		 */
		PhongIntegrator();

		float3 GetColor(Ray &ray, const Scenes::Scene &scene);
	};
}

#endif // RAYTRACER_PHONGINTEGRATOR_H
