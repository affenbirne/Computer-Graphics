#ifndef RAYTRACER_SIMPLEACCELERATOR_H
#define RAYTRACER_SIMPLEACCELERATOR_H

#include <vector>

#include <Raytracer/IAccelerator.h>
#include <Raytracer/Ray.h>
#include <Raytracer/Scenes/Scene.h>

// this is a dummy accelerator: no hierarchical data structure, every ray is
// tested against every object

namespace Raytracer
{
	/**
	 * A simple accelerator that uses brute force testing of all objects to find intersections.
	 */
	class SimpleAccelerator : public IAccelerator
	{
	private:
		/**
		 * A list of all primitives in the scene
		 */
		std::vector<Scenes::IPrimitive *> objects;

	public:
		bool Cast(const Ray &ray, float maxDistance) const;
		void Init(const Scenes::Scene &scene);
		bool Trace(const Ray &ray, RayHit &hit) const;
	};
}

#endif // RAYTRACER_SIMPLEACCELERATOR_H
