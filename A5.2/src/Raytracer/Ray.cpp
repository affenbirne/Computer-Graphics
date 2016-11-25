#include <HLSL.h>

#include <Raytracer/Raytracer.h>

using namespace Raytracer;

Ray::Ray()
{
}

Ray::Ray(const float3 &origin, const float3 &direction)
{
	this->origin = origin;
	this->direction = normalize(direction);
}

float3 Ray::GetDirection() const
{
	return direction;
}

float3 Ray::GetOrigin() const
{
	return origin;
}

float3 Ray::Reflect(float3 vector, float3 normal)
{
	float t = dot(vector, normal);

	if (t <= 0)
		return float3(0, 0, 0);

	return normal * 2.0f * t - vector;
}

void Ray::Set(const float3 &origin, const float3 &direction)
{
	this->origin = origin;
	this->direction = direction;
}

void Ray::SetDirection(const float3 &direction)
{
	this->direction = direction;
}

void Ray::SetOrigin(const float3 &origin)
{
	this->origin = origin;
}
