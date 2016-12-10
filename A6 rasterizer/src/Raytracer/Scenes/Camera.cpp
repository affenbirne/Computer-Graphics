#include <gtc/matrix_transform.hpp>

#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;
using namespace Raytracer::Scenes;

const float Camera::DefaultFov = 53.13f;
const float Camera::DefaultNearClip = 1.0f;
const float Camera::DefaultFarClip = 10.0f;

Camera::Camera()
{
	SetCamera(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f), 53.13f, 1.0f, 1.0f, 10.0f);
}

Camera::Camera(const vec3 &eye, const vec3 &lookat, const vec3 &up, 
               float fov, float aspect, float nearClip, float farClip)
{
	SetCamera(eye, lookat, up, fov, aspect, nearClip, farClip);
}

glm::vec3 Camera::GetEye() const
{
  return eye;
}

glm::vec3 Camera::GetLookAt() const
{
  return lookat;
}

glm::vec3 Camera::GetUp() const
{
  return up;
}

float Camera::GetAspect() const
{
	return aspect;
}

float Camera::GetFov() const
{
	return fov;
}

float Camera::GetNearClip() const
{
  return nearClip;
}

float Camera::GetFarClip() const
{
  return farClip;
}

//glm::mat4  Camera::GetProjectionTransform() const
//{
//  return projectionTransform;
//}
//
//glm::mat4  Camera::GetViewTransform() const
//{
//  return viewTransform;
//}
//
//glm::mat4  Camera::GetViewProjectionTransform() const
//{
//  return viewProjectionTransform;
//}

void Camera::SetCamera(const vec3 &eye, const vec3 &lookat, const vec3 &up, float fov,
					   float aspect, float nearClip, float farClip)
{
	if (fov <= 0.0f || fov >= 180.0f || aspect <= 0.0f || farClip <= 0.0f)
		return;

	SetPosition(eye);
	this->fov = fov;
	this->aspect = aspect;
  this->nearClip = nearClip;
  this->farClip = farClip;
  this->eye = eye;
  this->lookat = lookat;
  this->up = up;

	vec3 w = normalize(lookat - eye);
	u = normalize(cross(w, up));
	v = normalize(cross(w, u));

	float uscale = 2.0f * tanf(0.5f * fov * 3.14159265358979323846f / 180.0f);

	u *= uscale;
	v *= uscale / aspect;

	Vp = w - 0.5f * u - 0.5f * v;
  
	SetGlobalTransformation(inverse(lookAt(eye, lookat, up)));
}

void Camera::SpawnRay(float x, float y, Ray &ray) const
{
	vec3 dir = Vp + x * u + y * v;
	ray.Set(GetPosition(), normalize(dir));
}

bool Raytracer::Scenes::Camera::IsInstanceOf(SceneObjectType type) const
{
	return (type == SceneObjectType_Camera);
}
