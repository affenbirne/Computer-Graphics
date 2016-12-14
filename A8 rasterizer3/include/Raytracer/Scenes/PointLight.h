#ifndef RAYTRACER_SCENES_POINTLIGHT_H
#define RAYTRACER_SCENES_POINTLIGHT_H

#include <glm.hpp>

#include <Raytracer/Intersection.h>
#include <Raytracer/Scenes/Light.h>

namespace Raytracer
{
	struct Sample;

	namespace Scenes
	{
		class Scene;

		/**
		 * A point light that radiates light in all directions. 
		 */
		class PointLight : public Light
		{
		private:
			/**
			 * The intensity of the light
			 */
			glm::vec3 intensity;

		public:
			/**
			 * Constructs a new point light.
			 *
			 * @param intensity The color and intensity of the light
			 */
			PointLight(const glm::vec3 &intensity);

			glm::vec3 ComputeDirectContribution(const Accelerator *accelerator,
				const Intersection &intersection);

			glm::vec3 GetIntensity() const;

			virtual bool IsInstanceOf(SceneObjectType type) const;
		};
	}
}

#endif // RAYTRACER_SCENES_POINTLIGHT_H
