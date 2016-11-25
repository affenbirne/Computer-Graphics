#ifndef RAYTRACER_SCENES_MATERIAL_H
#define RAYTRACER_SCENES_MATERIAL_H

#include "HLSL.h"

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
			float3 ambient;

			/**
			 * The diffuse color
			 */
			float3 diffuse;

			/**
			 * The specular color
			 */
			float3 specular;

			/**
			 * The emissive color
			 */
			float3 emissive;

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
			float3 GetAmbient();

			/**
			 * Gets the diffuse color
			 */
			float3 GetDiffuse();

			/**
			 * Gets the emissive color
			 */
			float3 GetEmissive();
			
			/**
			 * Gets the shininess, which determines the shape of the highlight
			 */
			float GetShininess();
			
			/**
			 * Gets the specular color
			 */
			float3 GetSpecular();

			/**
			 * Sets the ambient color
			 */
			void SetAmbient(float3 &color);

			/**
			 * Sets the diffuse color
			 */
			void SetDiffuse(float3 &color);

			/**
			 * Sets the emissive color
			 */
			void SetEmissive(float3 &color);

			/**
			 * Sets the shininess, which determines the shape of the highlight
			 */
			void SetShininess(float shininess);

			/**
			 * Sets the specular color
			 */
			void SetSpecular(float3 &color);
		};
	}
}

#endif // RAYTRACER_SCENES_MATERIAL_H
