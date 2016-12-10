#include <Raytracer/Raytracer.h>

using namespace Raytracer::Objects;

void Triangle::SetVertex(int i, glm::vec3 position, glm::vec3 normal, glm::vec3 color)
{
	this->position[i] = position;
	this->normal[i] = normal;
	this->color[i] = color;
}
