#ifndef RAYTRACER_SCENES_MATERIAL_H
#define RAYTRACER_SCENES_MATERIAL_H

#include <glm.hpp>

namespace Raytracer
{
	namespace Scenes
	{
		/**
		 * A Material that determines the visual properties of an object
		 */
		class Material
		{
		private:
			/**
			 * The ambient color
			 */
			glm::vec3 ambient;

			/**
			 * The diffuse color
			 */
			glm::vec3 diffuse;

			/**
			 * The specular color
			 */
			glm::vec3 specular;

			/**
			 * The emissive color
			 */
			glm::vec3 emissive;

			/**
			 * The shininess, which determines the shape of the highlight
			 */
			float shininess;

		public:
			/**
			 * Constructs a new default material.
			 */
			Material();

			/**
			 * Gets the ambient color
			 */
			glm::vec3 GetAmbient();

			/**
			 * Gets the diffuse color
			 */
			glm::vec3 GetDiffuse();

			/**
			 * Gets the emissive color
			 */
			glm::vec3 GetEmissive();
			
			/**
			 * Gets the shininess, which determines the shape of the highlight
			 */
			float GetShininess();
			
			/**
			 * Gets the specular color
			 */
			glm::vec3 GetSpecular();

			/**
			 * Sets the ambient color
			 */
			void SetAmbient(glm::vec3 &color);

			/**
			 * Sets the diffuse color
			 */
			void SetDiffuse(glm::vec3 &color);

			/**
			 * Sets the emissive color
			 */
			void SetEmissive(glm::vec3 &color);

			/**
			 * Sets the shininess, which determines the shape of the highlight
			 */
			void SetShininess(float shininess);

			/**
			 * Sets the specular color
			 */
			void SetSpecular(glm::vec3 &color);
		};
	}
}

#endif // RAYTRACER_SCENES_MATERIAL_H
