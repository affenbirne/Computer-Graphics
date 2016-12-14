#ifndef RAYTRACER_SIMPLEACCELERATOR_H
#define RAYTRACER_SIMPLEACCELERATOR_H

#include <vector>

#include <Raytracer/Accelerator.h>
// #include <Raytracer/Ray.h>

namespace Raytracer
{
	class Ray;
	class RayHit;

	namespace Scenes
	{
		class Light;
		class PhysicalObject;
		class Scene;
		class SceneObject;
	}

	/**
	 * A simple accelerator that uses brute force testing of all objects to find intersections.
	 */
	class SimpleAccelerator : public Accelerator
	{
	private:
		/**
		 * A list of all physical objects in the scene
		 */
		std::vector<Scenes::PhysicalObject *> physicalObjects;

		std::vector<Scenes::Light *> lights;

		void AddObject(const Scenes::SceneObject *object);

	public:
		virtual const std::vector<Scenes::Light *> &GetLights() const;

		virtual bool HitTest(const Ray &ray, RayHit *hit) const;

		virtual void SetScene(const Scenes::Scene *scene);
	};
}

#endif // RAYTRACER_SIMPLEACCELERATOR_H
