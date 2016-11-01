#pragma once
struct Vector
{
	float x, y, z;
};

class Mesh
{
protected:
	static int next_id;
public:
	Mesh(std::string name, int vertices, int faces, float scaling, Vector center);
	Mesh();
	~Mesh();
	int id;
	int vertices;
	int faces;
	std::string name;
	float scaling;
	Vector center;
	std::string to_string();
};

