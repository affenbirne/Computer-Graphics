#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include <HLSLEx.h>

namespace Raytracer
{
	class Ray;

	namespace Scenes
	{
		class Camera
		{
		private:
			int width;
			int height;
			float fov;
			float3 eye;
			float3 lookat;
			float3 up;

			float3 u, v;
			float3 Vp;

		public:
			Camera();
			Camera(int width, int height, const float3 &eye, const float3 &lookat,
				const float3 &up, float fov);

			int GetHeight() const;
			int GetWidth() const;
			void SetCamera(int width, int height, const float3 &eye, const float3 &lookat,
				const float3 &up, float fov);
			void SpawnRay(float x, float y, Ray &ray) const;
		};
	}
}

#endif // RAYTRACER_CAMERA_H
