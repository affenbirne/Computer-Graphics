#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include <glm.hpp>

namespace Raytracer
{
	namespace Scenes
	{
		class Primitive;
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
		glm::vec3 origin;

		/**
		 * The ray direction
		 */
		glm::vec3 direction;

		float length;

	public:
		/**
		 * Constructs a new Ray object.
		 */
		Ray();

		/**
		 * Constructs a new Ray object with infinite length.
		 *
		 * @param origin The ray origin
		 * @param direction The ray direction. \a Ray will normalize this vector.
		 */
		Ray(const glm::vec3 &origin, const glm::vec3 &direction);

		/**
		 * Constructs a new Ray object.
		 *
		 * @param origin The ray origin
		 * @param direction The ray direction. \a Ray will normalize this vector.
		 * @param length The length of the ray
		 */
		Ray(const glm::vec3 &origin, const glm::vec3 &direction, float length);

		/**
		 * Gets the normalized ray direction.
		 *
		 * @return The normalized ray direction
		 */
		glm::vec3 GetDirection() const;

		/**
		 * Gets the length of the ray.
		 *
		 * @return The length of the ray. This may be infinite.
		 */
		float GetLength() const;

		/**
		 * Gets the ray origin
		 *
		 * @return The ray origin
		 */
		glm::vec3 GetOrigin() const;

		/**
		 * Sets the ray origin and direction and makes it infinite length.
		 *
		 * @param origin The ray origin
		 * @param direction The ray direction. \a Set will normalize this vector.
		 */
		void Set(const glm::vec3 &origin, const glm::vec3 &direction);

		/**
		 * Sets the ray origin, direction, and length.
		 *
		 * @param origin The ray origin
		 * @param direction The ray direction. \a Ray will normalize this vector.
		 * @param length The length of the ray
		 */
		void Set(const glm::vec3 &origin, const glm::vec3 &direction, float length);

		/**
		 * Sets the ray direction.
		 *
		 * @param direction The ray direction
		 */
		void SetDirection(const glm::vec3 &direction);

		/**
		 * Sets the length of the ray.
		 *
		 * @param length The length of the ray
		 */
		void SetLength(float length);

		/**
		 * Sets the ray origin
		 *
		 * @param origin The ray origin
		 */
		void SetOrigin(const glm::vec3 &origin);

		/**
		 * Creates a copy of this ray transformed using a given matrix.
		 *
		 * @param transformation The transformation matrix
		 * @return A copy of this ray after the transformation
		 */
		Ray Transform(glm::mat4x4 transformation) const;
	};
}

#endif // RAYTRACER_RAY_H
