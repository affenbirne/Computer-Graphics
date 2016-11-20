#ifndef RAYTRACER_ACCELERATOR_H
#define RAYTRACER_ACCELERATOR_H

#include <vector>

#include <Raytracer/Ray.h>
#include <Raytracer/RayHit.h>
#include <Raytracer/Scenes/Scene.h>

namespace Raytracer
{
	/**
	 * This interface provides methods for tracing rays through a scene.
	 */
	class IAccelerator
	{
	public:
		/**
		 * Traces a shadow ray.
		 *
		 * @param ray A ray
		 * @param maxDistance the maximum distance to search for an obstruction
		 * @return true if there is an obstacle along the path of the ray closer than maxDistance.
		 *   false if the path is clear.
		 */
		virtual bool Cast(const Ray &ray, float maxDistance) const = 0;

		/**
		* Prepares to trace rays through the given scene.
		*
		* @param scene The scene
		*/
		virtual void Init(const Scenes::Scene &scene) = 0;

		/**
		 * Traces a ray and returns information on the object hit if any.
		 *
		 * @param ray A ray
		 * @param hit A RayHit object that, on successful return, contains the object hit and the
		 *   distance to the intersection point.
		 * @return true if an object was hit, false if the ray left the scene without intersecting
		 *   an object.
		 */
		virtual bool Trace(const Ray &ray, RayHit &hit) const = 0;
	};
}

#endif // RAYTRACER_ACCELERATOR_H
