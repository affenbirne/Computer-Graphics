#ifndef RAYTRACER_SCENES_LIGHT_H
#define RAYTRACER_SCENES_LIGHT_H

#include <glm.hpp>

#include <Raytracer/Intersection.h>
#include <Raytracer/Scenes/SceneObject.h>

namespace Raytracer
{
	struct Sample;

	namespace Scenes
	{
		class Scene;

		/**
		 * A light source
		 */
		class Light : public SceneObject
		{
		public:
			/**
			 * Computes the direct contribution of this light in the illumination of a surface
			 * point.
			 *
			 * @param accelerator An accelerator object that can be used to trace secondary rays
			 *   through the scene
			 * @param intersection An intersection of a view ray with an object
			 * @return A color value representing the direct contribution
			 */
			virtual glm::vec3 ComputeDirectContribution(const Accelerator *accelerator,
				const Intersection &intersection) = 0;

			virtual bool IsInstanceOf(SceneObjectType type) const;
		};
	}
}

#endif // RAYTRACER_SCENES_LIGHT_H
