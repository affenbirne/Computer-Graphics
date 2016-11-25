#ifndef RACTRACER_SCENES_PRIMITIVE_H
#define RACTRACER_SCENES_PRIMITIVE_H

#include <HLSL.h>
#include <Raytracer/Ray.h>
#include <Raytracer/Intersection.h>

namespace Raytracer
{
	namespace Scenes
	{
		/**
		 * An interface implemented by all objects that can be intersected by a camera ray.
		 */
		class IPrimitive
		{
		public:
			/**
			 * Gets the extent of an axis-aligned bounding box.
			 * @param min Is set to the minimum of the bounding box coordinates.
			 * @param max Is set to the maximum of the bounding box coordinates.
			 */
			virtual void GetExtent(float3 &min, float3 &max) const = 0;

			/**
			 * Gets the coordinates, the view vector, the surface normal, and the material of an
			 * intersection.
			 * @param ray A ray intersecting this primitive. The intersected object and the
			 *   distance to the intersection must have previously been set using Ray::SetHit().
			 * @param intersection Is filled with the position, normal, view direction, and
			 *   material at the intersection given by \a ray.
			 */
			virtual void GetIntersection(const Ray &ray, float distance,
				Intersection &intersection) const = 0;

			/**
			* Tests whether a ray intersects this primitive and computes the closest intersection
			* point.
			* @param ray A ray
			* @param hit A RayHit object that will be set to this object and the distance to the
			*   intersection if the ray hits this object.
			* @return true if the ray hits this object, false otherwise
			*/
			virtual bool HitTest(const Ray &ray, RayHit &hit) const = 0;
		};
	}
}

#endif // RACTRACER_SCENES_PRIMITIVE_H
