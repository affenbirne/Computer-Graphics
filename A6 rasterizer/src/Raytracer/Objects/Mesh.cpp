#include <stdio.h>

#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace std;
using namespace Raytracer;
using namespace Raytracer::Scenes;
using namespace Raytracer::Objects;

Mesh::Mesh()
{

}

void Mesh::AddTriangle(Triangle &t)
{
	triangles.push_back(t);
}

const vector<Triangle> &Mesh::GetTriangles() const
{
	return triangles;
}

bool Mesh::IsInstanceOf(Scenes::SceneObjectType type) const
{
	return (type == SceneObjectType_Mesh);
}

bool Mesh::Load(const char *fileName)
{
	if (fileName == NULL)
		return false;

#ifdef __STDC_WANT_SECURE_LIB__
	FILE *file = NULL;
	fopen_s(&file, fileName, "rb");
#else
	FILE *file = fopen(fileName, "rb");
#endif

	if (file == NULL)
		return false;

	int triangleCount;

	if (fread(&triangleCount, 4, 1, file) != 1 || triangleCount < 0)
	{
		fclose(file);
		return false;
	}

	fseek(file, 0, SEEK_END);

	if (ftell(file) != triangleCount * sizeof(Triangle) + 4)
	{
		fclose(file);
		return false;
	}

	fseek(file, 4, SEEK_SET);

	for (int i = 0; i < triangleCount; i++)
	{
		Triangle t;

		for (int v = 0; v < 3; v++)
		{
			if (fread(&t.position[v], sizeof(vec3), 1, file) != 1 ||
				fread(&t.normal[v], sizeof(vec3), 1, file) != 1 ||
				fread(&t.color[v], sizeof(vec3), 1, file) != 1)
			{
				fclose(file);
				return false;
			}
		}

		triangles.push_back(t);
	}

	fclose(file);
	return true;
}
