#include <Raytracer/Raytracer.h>

using namespace Raytracer;
using namespace Raytracer::Scenes;

Accelerator::Accelerator()
{
	scene = NULL;
}

const Scene *Accelerator::GetScene() const
{
	return scene;
}

void Accelerator::SetScene(const Scenes::Scene *scene)
{
	this->scene = scene;
}
