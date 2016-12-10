#include <limits>

#include <glm.hpp>

#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;

Ray::Ray()
{
	origin = vec3(0.0f);
	direction = vec3(0.0f);
	length = 0.0f;
}

Ray::Ray(const vec3 &origin, const vec3 &direction)
{
	Set(origin, direction);
}

Ray::Ray(const vec3 &origin, const vec3 &direction, float length)
{
	Set(origin, direction, length);
}

vec3 Ray::GetDirection() const
{
	return direction;
}

float Ray::GetLength() const
{
	return length;
}

vec3 Ray::GetOrigin() const
{
	return origin;
}

void Ray::Set(const vec3 &origin, const vec3 &direction)
{
	this->origin = origin;
	this->direction = normalize(direction);
	this->length = std::numeric_limits<float>::infinity();
}

void Ray::Set(const vec3 &origin, const vec3 &direction, float length)
{
	this->origin = origin;
	this->direction = direction;
	this->length = length;
}

void Ray::SetDirection(const vec3 &direction)
{
	this->direction = direction;
}

void Ray::SetLength(float length)
{
	this->length = length;
}

void Ray::SetOrigin(const vec3 &origin)
{
	this->origin = origin;
}

Ray Ray::Transform(mat4x4 transformation) const
{
	vec3 newOrigin = vec3(transformation * vec4(origin, 1.0f));
	vec3 newDirection = vec3(transformation * vec4(direction, 0.0f));

	return Ray(newOrigin, newDirection);
}
