#ifndef RAYTRACER_SIMPLEINTEGRATOR_H
#define RAYTRACER_SIMPLEINTEGRATOR_H

#include <Raytracer/IIntegrator.h>

namespace Raytracer
{
	namespace Scenes
	{
		class Scene;
	}

	/**
	 * Calculates the visible color seen by a ray using the Simple illumination model.
	 */
	class SimpleIntegrator : public IIntegrator
	{
	private:
		/**
		 * The background color seen by rays that exit the scene
		 */
		float3 backgroundColor;

	public:
		/**
		 * Constructs a new SimpleIntegrator object.
		 */
		SimpleIntegrator();

		float3 GetColor(Ray &ray, const Scenes::Scene &scene);
	};
}

#endif // RAYTRACER_PHONGINTEGRATOR_H
