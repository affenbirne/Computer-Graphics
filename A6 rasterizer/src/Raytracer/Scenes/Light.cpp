#include <Raytracer/Raytracer.h>

using namespace Raytracer::Scenes;

bool Light::IsInstanceOf(SceneObjectType type) const
{
	return (type == SceneObjectType_Light);
}
