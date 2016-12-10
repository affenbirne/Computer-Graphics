#define RAYTRACER_USE_FOREACH
#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

Scene::Scene()
{
	activeCamera = NULL;
}

Camera *Scene::GetActiveCamera() const
{
	return activeCamera;
}

bool Scene::IsInstanceOf(SceneObjectType type) const
{
	return (type == SceneObjectType_Scene);
}

void Scene::SetActiveCamera(Camera *camera)
{
	this->activeCamera = camera;
}
