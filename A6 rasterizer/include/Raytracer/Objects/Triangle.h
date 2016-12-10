#ifndef RAYTRACER_OBJECTS_TRIANGLE_H
#define RAYTRACER_OBJECTS_TRIANGLE_H

#include <glm.hpp>

namespace Raytracer
{
	namespace Objects
	{
		struct Triangle
		{
			glm::vec3 position[3];

			glm::vec3 normal[3];

			glm::vec3 color[3];

			void SetVertex(int i, glm::vec3 position, glm::vec3 normal, glm::vec3 color);
		};
	}
}

#endif // RAYTRACER_OBJECTS_TRIANGLE_H
