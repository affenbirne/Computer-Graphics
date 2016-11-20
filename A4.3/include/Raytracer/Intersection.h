#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

#include <HLSL.h>

namespace Raytracer
{
	namespace Scenes
	{
		class Material;
	}

	/**
	 * Stores information on a ray-surface intersection
	 */
	struct Intersection
	{
		/**
		 * The position of the intersection point
		 */
		float3 position;

		/**
		 * The surface normal at the intersection point
		 */
		float3 normal;

		/**
		 * The direction from the intersection point to the camera
		 */
		float3 viewDirection;

		/**
		 * The surface material at the intersection point
		 */
		Scenes::Material *material;
	};
}

#endif // RAYTRACER_INTERSECTION_H
