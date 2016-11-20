#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include <HLSL.h>

namespace Raytracer
{
	namespace Scenes
	{
		class IPrimitive;
	}

	/**
	 * Represents a ray in the scene.
	 */
	class Ray
	{
	private:
		/**
		 * The ray origin
		 */
		float3 origin;

		/**
		 * The ray direction
		 */
		float3 direction;

	public:
		/**
		 * Constructs a new Ray object.
		 */
		Ray();

		/**
		 * Constructs a new Ray object.
		 *
		 * @param origin The ray origin
		 * @param direction The ray direction. \a Ray will normalize this vector.
		 */
		Ray(const float3 &origin, const float3 &direction);

		/**
		 * Gets the normalized ray direction.
		 *
		 * @return The normalized ray direction
		 */
		float3 GetDirection() const;

		/**
		 * Gets the ray origin
		 *
		 * @return The ray origin
		 */
		float3 GetOrigin() const;

		/**
		 * Computes a reflection direction.
		 *
		 * @param vector The incoming vector
		 * @param normal The surface normal
		 * @return The outgoing reflection vector
		 */
		static float3 Reflect(float3 vector, float3 normal);

		/**
		 * Sets the ray origin and direction.
		 *
		 * @param origin The ray origin
		 * @param direction The ray direction. \a Set will normalize this vector.
		 */
		void Set(const float3 &origin, const float3 &direction);

		/**
		 * Sets the ray direction.
		 *
		 * @param direction The ray direction
		 */
		void SetDirection(const float3 &direction);

		/**
		 * Sets the ray origin
		 *
		 * @param origin The ray origin
		 */
		void SetOrigin(const float3 &origin);
	};
}

#endif // RAYTRACER_RAY_H
