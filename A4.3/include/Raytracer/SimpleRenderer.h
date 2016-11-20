#ifndef RAYTRACER_SIMPLERENDERER_H
#define RAYTRACER_SIMPLERENDERER_H

#include <Raytracer/Image.h>
#include <Raytracer/Renderer.h>
#include <Raytracer/Scenes/Scene.h>

namespace Raytracer
{
	class SimpleRenderer : public Renderer
	{
	public:
		void Render(Scenes::Scene &scene, const Scenes::Camera &camera, Image &image) const;
	};
}

#endif // RAYTRACER_SIMPLERENDERER_H
