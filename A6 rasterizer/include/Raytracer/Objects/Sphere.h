#ifndef RAYTRACER_OBJECTS_SPHERE_H
#define RAYTRACER_OBJECTS_SPHERE_H

#include <Raytracer/Scenes/PhysicalObject.h>

namespace Raytracer
{
	namespace Scenes
	{
		class Material;
		class Scene;
	}

	namespace Objects
	{
		/**
		 * A sphere
		 */
		class Sphere : public Scenes::PhysicalObject
		{
		private:
			/**
			 * The surface material
			 */
			Scenes::Material *material;

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
			Sphere(float radius);

			/**
			 * Constructs a new sphere.
			 * @param center The position of the center point
			 * @param radius The radius
			 * @param The surface material
			 */
			Sphere(float radius, Scenes::Material *material);

			void GetIntersection(const RayHit &hit, Intersection &intersection) const;
			bool HitTest(const Ray &ray, RayHit *hit) const;

			virtual bool IsInstanceOf(Scenes::SceneObjectType type) const;
		};
	}
}

#endif // RAYTRACER_OBJECTS_SPHERE_H
