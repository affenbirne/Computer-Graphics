#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

#include <glm.hpp>

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
		glm::vec3 position;

		/**
		 * The surface normal at the intersection point
		 */
		glm::vec3 normal;

		/**
		 * The direction from the intersection point to the camera
		 */		 
		glm::vec3 viewDirection;

		/**
		 * The surface material at the intersection point
		 */
		Scenes::Material *material;

		Intersection Transform(glm::mat4x4 transformation) const;
	};
}

#endif // RAYTRACER_INTERSECTION_H
