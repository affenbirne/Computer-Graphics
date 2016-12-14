#ifndef RAYTRACER_OBJECTS_MESH_H
#define RAYTRACER_OBJECTS_MESH_H

#include <vector>

#include <Raytracer/Objects/Triangle.h>
#include <Raytracer/Scenes/SceneObject.h>

namespace Raytracer
{
	namespace Objects
	{
		class Mesh  : public Scenes::SceneObject
		{
		private:
			std::vector<Triangle> triangles;

		public:
			Mesh();

			void AddTriangle(Triangle &t);

			const std::vector<Triangle> &GetTriangles() const;

			virtual bool IsInstanceOf(Scenes::SceneObjectType type) const;

			bool Load(const char *fileName);
		};
	}
}

#endif // RAYTRACER_OBJECTS_MESH_H
