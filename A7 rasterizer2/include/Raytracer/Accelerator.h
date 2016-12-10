#ifndef RAYTRACER_ACCELERATOR_H
#define RAYTRACER_ACCELERATOR_H

#include <vector>

#include <Raytracer/Ray.h>
#include <Raytracer/RayHit.h>
#include <Raytracer/Scenes/Scene.h>

namespace Raytracer
{
	namespace Scenes
	{
		class Light;
	}

	/**
	 * An Accelerator provides methods for tracing rays through a scene.
	 */
	class Accelerator
	{
	protected:
		const Scenes::Scene *scene;

	public:
		/**
		 * Constructs a new Accelerator object.
		 */
		Accelerator();

		/**
		 * Retrieves a list of all lights in the scene.
		 *
		 * @return A list of all lights in the scene
		 */
		virtual const std::vector<Scenes::Light *> &GetLights() const = 0;
		
		/**
		 * Retrieves the scene this Accelerator works on.
		 *
		 * @return The scene this Accelerator works on
		 */
		const Scenes::Scene *GetScene() const;

		/**
		 * Traces a ray and returns information on the object hit if any.
		 *
		 * @param ray A ray
		 * @param hit A RayHit object that, on successful return, contains the object hit and the
		 *   distance to the intersection point.
		 * @return true if an object was hit, false if the ray left the scene without intersecting
		 *   an object.
		 */
		virtual bool HitTest(const Ray &ray, RayHit *hit) const = 0;

		/**
		 * Sets the scene this Accelerator works on. This must be called for any other methods to
		 * return meaningful results.
		 *
		 * @param scene The scene this Accelerator works on
		 */
		virtual void SetScene(const Scenes::Scene *scene);
	};
}

#endif // RAYTRACER_ACCELERATOR_H
