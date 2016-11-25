#ifndef RAYTRACER_SCENES_LIGHT_H
#define RAYTRACER_SCENES_LIGHT_H

#include <Raytracer/Intersection.h>

namespace Raytracer
{
	struct Sample;

	namespace Scenes
	{
		class Scene;

		/**
		 * An interface implemented by a light source
		 */
		class ILight
		{
		public:
			/**
			 * Computes the direct contribution of this light in the illumination of a surface
			 * point.
			 *
			 * @param intersection An intersection of a view ray with an object
			 * @param scene The scene that contains this light and the intersected object
			 * @return A color value representing the direct contribution
			 */
			virtual float3 ComputeDirectContribution(const Intersection &intersection,
				const Scene &scene) = 0;
		};
	}
}

#endif // RAYTRACER_SCENES_LIGHT_H
