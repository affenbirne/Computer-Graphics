#ifndef RAYTRACER_SCENES_SCENE_H
#define RAYTRACER_SCENES_SCENE_H

#include <Raytracer/Scenes/SceneObject.h>

namespace Raytracer
{
	class Ray;

	namespace Scenes
	{
		class Camera;

		class Scene : public SceneObject
		{
		private:
			/**
			 * The camera that is to be used for rendering the scene
			 */
			Camera *activeCamera;

		public:
			/**
			 * Constructs a new Scene object.
			 */
			Scene();

			/**
			 * Retrieves the active camera, i.e. the camera object to be used for rendering the
			 * scene.
			 *
			 * @return The active camera or NULL if there is no active camera
			 */
			Camera *GetActiveCamera() const;

			virtual bool IsInstanceOf(SceneObjectType type) const;

			/**
			 * Sets the active camera, i.e. the camera object to be used for rendering the scene.
			 *
			 * @param camera The new active camera or NULL to set no active camera
			 */
			void SetActiveCamera(Camera *camera);
		};
	}
}

#endif // RAYTRACER_SCENES_SCENE_H
