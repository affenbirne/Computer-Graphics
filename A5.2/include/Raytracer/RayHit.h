#ifndef RAYTRACER_RAYHIT_H
#define RAYTRACER_RAYHIT_H

#include <Raytracer/Intersection.h>

namespace Raytracer
{
	class Ray;

	namespace Scenes
	{
		class IPrimitive;
	}

	/**
	 * Stores information on the object hit by a ray and the distance to the intersection point.
	 */
	class RayHit
	{
	private:
		/**
		 * The ray
		 */
		const Ray *ray;

		/**
		 * The distance from the ray origin to the intersection point
		 */
		float distance;

		/**
		 * The object that was hit or NULL if no object was hit
		 */
		const Scenes::IPrimitive *object;
		
	public:
		/**
		 * Constructs a new RayHit object.
		 */
		RayHit();

		/**
		 * Constructs a new RayHit object.
		 *
		 * @param hit Another RayHit object that is copied into the new one.
		 */
		RayHit(RayHit &hit);

		/**
		 * Constructs a new RayHit object.
		 *
		 * @param ray A ray
		 */
		RayHit(const Ray *ray);

		/**
		 * Constructs a new RayHit object.
		 *
		 * @param ray A ray
		 * @param distance The distance from the ray origin to the intersection point
		 * @param object The object that was hit or NULL if no object was hit
		 */
		RayHit(const Ray *ray, float distance, const Scenes::IPrimitive *object);

		/**
		 * Gets the distance from the ray origin to the intersection point.
		 *
		 * @return The distance from the ray origin to the intersection point
		 */
		float GetDistance() const;

		/**
		 * Fills an Intersection object with information on the intersection point.
		 *
		 * @param intersection The intersection object
		 * @return true if the operation was successful or false if no object was hit
		 */
		bool GetIntersection(Intersection &intersection);

		/**
		 * Gets the object that was hit or NULL if no object was hit
		 *
		 * @return The object that was hit or NULL if no object was hit
		 */
		const Scenes::IPrimitive *GetObject() const;

		/**
		 * Gets the ray.
		 *
		 * @return The ray
		 */
		const Ray *GetRay() const;

		/**
		 * Sets the distance and the object that was hit.
		 *
		 * @param distance The distance from the ray origin to the intersection point
		 * @param object The object that was hit or NULL if no object was hit
		 */
		void Set(float distance, const Scenes::IPrimitive *object);

		/**
		 * Sets the ray, distance and the object that was hit.
		 *
		 * @param ray The ray
		 * @param distance The distance from the ray origin to the intersection point
		 * @param object The object that was hit or NULL if no object was hit
		 */
		void Set(const Ray *ray, float distance, const Scenes::IPrimitive *object);

		/**
		 * Sets the ray.
		 *
		 * @param ray The ray
		 */
		void SetRay(const Ray *ray);
	};
}

#endif // RAYTRACER_RAYHIT_H
