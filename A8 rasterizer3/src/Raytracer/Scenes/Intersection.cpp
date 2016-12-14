#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;

Intersection Intersection::Transform(mat4x4 transformation) const
{
	Intersection i;

	i.position = vec3(transformation * vec4(position, 1.0f));
	i.normal = vec3(transformation * vec4(normal, 0.0f));
	i.viewDirection = vec3(transformation * vec4(viewDirection, 0.0f));
	i.material = material;

	return i;
}
