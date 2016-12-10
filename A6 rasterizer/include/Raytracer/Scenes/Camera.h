#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include <glm.hpp>

namespace Raytracer
{
	class Ray;

	namespace Scenes
	{
		class Camera : public SceneObject
		{
		private:
			float fov;
			float aspect;
      float nearClip;
      float farClip;

      glm::vec3 eye;
      glm::vec3 up;
      glm::vec3 lookat;
			glm::vec3 u, v;
			glm::vec3 Vp;
      //glm::mat4 projectionTransform;
      //glm::mat4 viewTransform;
      //glm::mat4 viewProjectionTransform;

		public:
			static const float DefaultFov;
      static const float DefaultNearClip;
      static const float DefaultFarClip;

			Camera();

      /**
       * Constructor of the camera with the following parameters:
       * @param eye the position of the camera
       * @param lookat position, where the camera is looking at
       * @param up normalized up vector, determines the orientation of the camera
       * @param fov the field of view of the camera, in degree
       * @param aspect the aspect ratio of the camera
       * @param nearClip the distance of the near clipping plane to the camera
       * @param farClip the distance of the far clipping plane to the camera
       */
			Camera(const glm::vec3 &eye, const glm::vec3 &lookat, const glm::vec3 &up, 
             float fov, float aspect, float nearClip, float farClip);

      glm::vec3 GetEye() const;
      glm::vec3 GetLookAt() const;
      glm::vec3 GetUp() const;

      /**
       * @return The aspect ratio of the camera
       */
			float GetAspect() const;

      /**
       * @return The field of view of the Camera (in degree)
       */
			float GetFov() const;

      /**
       * @return distance of the near clipping plane from the camera
       */
      float GetNearClip() const;

      /**
       * @return distance of the far clipping plane from the camera
       */
      float GetFarClip() const;

      ///**
      // * Get the projection transform matrix. The matrix is not created here.
      // * @return the projection transform matrix.
      // */
      //glm::mat4  GetProjectionTransform() const;

      ///**
      // * Get the view transform matrix. The matrix is not created here.
      // * @return the view transform matrix.
      // */
      //glm::mat4  GetViewTransform() const;

      ///**
      // * Get the combined view and projection transform matrix. 
      // * The matrix is not created here.
      // * @return the view projection transform matrix.
      // */
      //glm::mat4  GetViewProjectionTransform() const;

			virtual bool IsInstanceOf(SceneObjectType type) const;

      /**
       * Set the properties of the camera.
       * @param eye the position of the camera
       * @param lookat position, where the camera is looking at
       * @param up normalized up vector, determines the orientation of the camera
       * @param fov the field of view of the camera, in degree
       * @param aspect the aspect ratio of the camera
       * @param nearClip the distance of the near clipping plane to the camera
       * @param farClip the distance of the far clipping plane to the camera
       */
			void SetCamera(const glm::vec3 &eye, const glm::vec3 &lookat, const glm::vec3 &up,
				             float fov, float aspect, float nearClip, float farClip);

			void SpawnRay(float x, float y, Ray &ray) const;
		};
	}
}

#endif // RAYTRACER_CAMERA_H
