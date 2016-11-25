#ifndef RAYTRACER_OBJECTS_SPHERE_H
#define RAYTRACER_OBJECTS_SPHERE_H

#include <Raytracer/Scenes/IPrimitive.h>
// #include "HLSLEx.h"

namespace Raytracer
{
	namespace Scenes
	{
		class Material;
	}

	namespace Objects
	{
		/**
		 * A sphere
		 */
		class Sphere : public Scenes::IPrimitive
		{
		private:
			/**
			 * The surface material
			 */
			Scenes::Material *material;

			/**
			 * The position of the center point
			 */
			float3 center;

			/**
			 * The radius
			 */
			float radius;

			/**
			 * The precomputed square of the radius
			 */
			float radius2;

		public:
			/**
			 * Constructs a new sphere.
			 * @param center The position of the center point
			 * @param radius The radius
			 */
			Sphere(const float3 &center, float radius);

			/**
			 * Constructs a new sphere.
			 * @param center The position of the center point
			 * @param radius The radius
			 * @param The surface material
			 */
			Sphere(const float3 &center, float radius, Scenes::Material *material);

			void GetExtent(float3 &min, float3 &max) const;
			void GetIntersection(const Ray &ray, float distance, Intersection &intersection) const;
			bool HitTest(const Ray &ray, RayHit &hit) const;
		};
	}
}

#endif // RAYTRACER_OBJECTS_SPHERE_H
