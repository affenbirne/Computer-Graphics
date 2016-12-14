#include <Raytracer/Raytracer.h>

using namespace Raytracer::Scenes;

bool PhysicalObject::IsInstanceOf(SceneObjectType type) const
{
	return (type == SceneObjectType_PhysicalObject);
}
