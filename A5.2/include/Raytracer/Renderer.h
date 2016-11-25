#ifndef RAYTRACER_RENDERER_H
#define RAYTRACER_RENDERER_H

#include <HLSL.h>

#include <Raytracer/Image.h>
#include <Raytracer/Scenes/Camera.h>
#include <Raytracer/Scenes/Scene.h>

namespace Raytracer
{
	/**
	 * Renders an image of a scene.
	 */
	class Renderer
	{
	protected:
		/**
		 * Renders a single pixel.
		 *
		 * @param scene The scene
		 * @param camera The camera
		 * @param x The x coordinate of the pixel
		 * @param y The y coordinate of the pixel
		 * @return The color of the pixel
		 */
		virtual float3 RenderPixel(Scenes::Scene &scene, const Scenes::Camera &camera,
			int x, int y) const;

	public:
		/**
		 * Renders an image of a scene.
		 *
		 * @param scene The scene
		 * @param camera The camera
		 * @param image The image. The current dimensions of this image determine the size of the
		 *   rendering.
		 */
		virtual void Render(Scenes::Scene &scene, const Scenes::Camera &camera,
			Image &image) const = 0; 
	};
}

#endif // RAYTRACER_RENDERER_H
