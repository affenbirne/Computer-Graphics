#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

Camera::Camera()
{
	SetCamera(256, 256, float3(0.0f, 0.0f, 10.0f), float3(0.0f, 0.0f, 0.0f),
		float3(0.0f, 1.0f, 0.0f), 53.13f);
}

Camera::Camera(int width, int height, const float3 &eye, const float3 &lookat, const float3 &up,
			   float fov)
{
	SetCamera(width, height, eye, lookat, up, fov);
}

int Camera::GetHeight() const
{
	return height;
}

int Camera::GetWidth() const
{
	return width;
}

void Camera::SetCamera(int width, int height, const float3 &eye, const float3 &lookat,
					   const float3 &up, float fov)
{
	if (width <= 0 || height <= 0 || fov <= 0.0f || fov >= 180.0f)
		return;

	this->width = width;
	this->height = height;
	this->eye = eye;
	this->lookat = lookat;
	this->up = up;
	this->fov = fov;

	float3 w = normalize(lookat - eye);
	u = normalize(cross(w, up));
	v = normalize(cross(w, u));

	float uscale = 2.0f * tanf(0.5f * fov * HLSL_EX_PI / 180.0f);

	u *= uscale;
	v *= uscale;

	Vp = w - 0.5f * u - 0.5f * height / width * v;

	u *= 1.0f / width;
	v *= 1.0f / width;
}

void Camera::SpawnRay(float x, float y, Ray &ray) const
{
	float3 dir = Vp + x * u + y * v;
	ray.Set(eye, normalize(dir));
}
