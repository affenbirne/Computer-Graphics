#ifndef RAYTRACER_SCENES_PHYSICALOBJECT_H
#define RAYTRACER_SCENES_PHYSICALOBJECT_H

#include <glm.hpp>

#include <Raytracer/Scenes/SceneObject.h>

namespace Raytracer
{
	namespace Scenes
	{
		class Scene;

		/**
		 * An object that can be hit by view rays
		 */
		class PhysicalObject : public SceneObject
		{
		public:
			/**
			 * Gets the coordinates, the view vector, the surface normal, and the material of an
			 * intersection.
			 * @param ray A ray intersecting this primitive. The intersected object and the
			 *   distance to the intersection must have previously been set using Ray::SetHit().
			 * @param intersection Is filled with the position, normal, view direction, and
			 *   material at the intersection given by \a ray.
			 */
			virtual void GetIntersection(const RayHit &hit, Intersection &intersection) const = 0;

			/**
			* Tests whether a ray intersects this primitive and computes the closest intersection
			* point.
			* @param ray A ray
			* @param hit A RayHit object that will be set to this object and the distance to the
			*   intersection if the ray hits this object.
			* @return true if the ray hits this object, false otherwise
			*/
			virtual bool HitTest(const Ray &ray, RayHit *hit) const = 0;

			virtual bool IsInstanceOf(SceneObjectType type) const;
		};
	}
}

#endif // RAYTRACER_SCENES_PHYSICALOBJECT_H
