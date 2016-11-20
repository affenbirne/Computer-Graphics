#ifndef RAYTRACER_SCENES_SCENE_H
#define RAYTRACER_SCENES_SCENE_H

#include <vector>

#include <HLSL.h>

namespace Raytracer
{
	class IAccelerator;
	class IIntegrator;
	class Ray;

	namespace Scenes
	{
		class ILight;
		class IPrimitive;

		class Scene
		{
		private:
			/**
			 * The accelerator object used to trace rays through the scene
			 */
			IAccelerator *accelerator;			
			
			/**
			 * A flag stating whether the accelerator needs to be reinitialized before rendering
			 */
			bool updateAccelerator;

			/**
			 * The list of objects in the scene
			 */
			std::vector<IPrimitive *> objects;
			
			/**
			 * The list of lights in the scene
			 */
			std::vector<ILight *> lights;

			/**
			 * The integrator object used to determine the visible properties of a surface point
			 */
			IIntegrator *surfaceIntegrator;

		public:
			/**
			 * Constructs a new scene.
			 *
			 * @param surfaceIntegrator The integrator object used to determine the visible
			 *   properties of a surface point
			 * @param accelerator The accelerator object used to trace rays through the scene
			 */
			Scene(IIntegrator *surfaceIntegrator, IAccelerator *accelerator);

			/**
			 * Adds a light to the scene.
			 *
			 * @param light A light
			 */
			void AddLight(ILight *light);

			/**
			 * Adds an object to the scene.
			 *
			 * @param object An object
			 */
			void AddObject(IPrimitive *object);

			/**
			 * Gets the accelerator object used to trace rays through the scene
			 */
			const IAccelerator *GetAccelerator() const;

			/**
			 * Gets a list of all lights in the scene
			 */
			const std::vector<ILight *> GetLights() const;

			/**
			 * Gets a list of all objects in the scene
			 */
			const std::vector<IPrimitive *> GetObjects() const;

			/**
			 * Computes the visible color for a ray entering the scene.
			 *
			 * @param ray A ray
			 * @return The color seen via \a ray.
			 */
			float3 Shade(Ray &ray);
		};
	}
}

#endif // RAYTRACER_SCENES_SCENE_H
