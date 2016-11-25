#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;
using namespace Raytracer::Objects;

Sphere::Sphere(const float3 &center, float radius)
{
  this->center = center;
  this->radius = radius;
  this->radius2 = radius * radius;
  this->material = NULL;
}

Sphere::Sphere(const float3 &center, float radius, Material *material)
{
  this->center = center;
  this->radius = radius;
  this->radius2 = radius * radius;
  this->material = material;
}

void Sphere::GetExtent(float3 &min, float3 &max) const
{
  min = center - radius;
  max = center + radius;
};

void Sphere::GetIntersection(const Ray &ray, float distance, Intersection &intersection) const
{
  intersection.position = ray.GetOrigin() + ray.GetDirection() * distance;
  intersection.viewDirection = -ray.GetDirection();
  intersection.normal = normalize(intersection.position - center);
  intersection.material = material;
}

bool Sphere::HitTest(const Ray &ray, RayHit &hit) const
{
  hit.Set(&ray, 0, NULL);
  // http://wiki.cgsociety.org/index.php/Ray_Sphere_Intersection
  float3 distance = ray.GetOrigin() - center;

  float a = dot(ray.GetDirection(), ray.GetDirection());
  float b = 2.0f * dot(ray.GetDirection(), distance);
  float c = dot(distance, distance) - radius2;

  float discriminant = b * b - 4.0f * a * c;
  if (discriminant < 0.0f)
    return false;

  float root = sqrtf(discriminant);
  float q;
  if (b < 0)
    q = (-b - root) / 2.0f;
  else
    q = (-b + root) / 2.0f;

  float t0 = q / a;
  float t1 = c / q;

  if (t0 > t1)
  {
    float t = t0;
    t0 = t1;
    t1 = t;
  }

  if (t1 < 0)
    return false;
  else if (t0 < 0)
    hit.Set(t1, this);
  else
    hit.Set(t0, this);

  return true;
}
