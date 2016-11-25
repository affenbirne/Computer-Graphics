#ifndef RAYTRACER_SCENES_POINTLIGHT_H
#define RAYTRACER_SCENES_POINTLIGHT_H

#include <HLSL.h>

#include <Raytracer/Intersection.h>
#include <Raytracer/Scenes/ILight.h>

namespace Raytracer
{
	struct Sample;

	namespace Scenes
	{
		class Scene;

		/**
		 * A point light that sends light in all directions. 
		 */
		class PointLight : public ILight
		{
		private:
			/**
			 * The position of the light
			 */
			float3 position;

			/**
			 * The intensity of the light
			 */
			float3 intensity;

		public:
			/**
			 * Constructs a new point light.
			 *
			 * @param position The position of the light
			 * @param intensity The color and intensity of the light
			 */
			PointLight(const float3 &position, const float3 &intensity);

			float3 ComputeDirectContribution(const Intersection &intersection, const Scene &scene);
		};
	}
}

#endif // RAYTRACER_SCENES_POINTLIGHT_H
