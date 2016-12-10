#ifndef RAYTRACER_RENDERER_H
#define RAYTRACER_RENDERER_H

#include <glm.hpp>

#include <Raytracer/Image.h>
#include <Raytracer/Scenes/Camera.h>
#include <Raytracer/Scenes/Scene.h>

namespace Raytracer
{
	/**
	 * Renders an image of a scene. The renderer object is not thread-safe.
	 */
	class Renderer
	{
	private:
		Accelerator *accelerator;
		IIntegrator *integrator;

	protected:
		/**
		 * Renders a single pixel.
		 *
		 * @param camera The camera
		 * @param x The normalized x coordinate of the pixel in the 0-1 range
		 * @param y The normalized y coordinate of the pixel in the 0-1 range
		 *
		 * @return The color of the pixel
		 */
		virtual glm::vec3 RenderPixel(const Scenes::Camera &camera, float x, float y) const;

		/**
		 * Renders an image.
		 *
		 * @param camera The camera to use for the rendering
		 * @param image The image to be filled with rendered pixels
		 */
		virtual void RenderImage(const Scenes::Camera &camera, Image *image) const = 0;

	public:
		/**
		 * Constructs a new Renderer object.
		 */
		Renderer();

		/**
		 * Destructs a Renderer object.
		 */
		virtual ~Renderer();

		/**
		 * Retrieves the IIntegrator interface used for rendering.
		 *
		 * @return The IIntegrator interface used for rendering. The Renderer object owns this
		 *   interface.
		 */
		IIntegrator *GetIntegrator() const;

		/**
		 * Sets the IIntegrator interface used for rendering.
		 *
		 * @param integrator The IIntegrator interface used for rendering. The Renderer object
		 *   takes ownership of this interface.
		 */
		void SetIntegrator(IIntegrator *integrator);

		/**
		 * Retrieves the Accelerator object used for rendering.
		 *
		 * @return The Accelerator object used for rendering. The Renderer object owns the
		 *   accelerator.
		 */
		Accelerator *GetAccelerator() const;

		/**
		 * Sets the Accelerator object used for rendering.
		 *
		 * @param accelerator The Accelerator object used for rendering. The Renderer object takes
		 *   ownership of the accelerator.
		 */
		void SetAccelerator(Accelerator *accelerator);

		/**
		 * Renders an image of a scene.
		 *
		 * @param scene The scene
		 * @param width The image width in pixels
		 * @param height The image height in pixels
		 * @return The rendered image or NULL if the rendering failed
		 * @remarks You cannot use the same Renderer object to render different scenes
		 *   simultaneously.
		 */
		Image *Render(const Scenes::Scene &scene, int width, int height); 
	};
}

#endif // RAYTRACER_RENDERER_H
