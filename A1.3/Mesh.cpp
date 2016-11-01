#include "stdafx.h"
#include "Mesh.h"

using namespace std;

int Mesh::next_id = 0;

bool operator==(Mesh const& lmesh, Mesh const& rmesh)
{
	//Meshs are equal if theire id is equal because the id is unique
	return (lmesh.id == rmesh.id);
}

Mesh::Mesh()
{
	this->name = "";
	this->vertices = 0;
	this->faces = 0;
	this->scaling = 0;
	this->center.x = 0;
	this->center.y = 0;
	this->center.z = 0;

	this->id = next_id;
	++next_id;
}
Mesh::Mesh(string name, int vertices, int faces, float scaling, Vector center)
{
	this->name = name;
	this->vertices = vertices;
	this->faces = faces;
	this->scaling = scaling;
	this->center = center;

	this->id = next_id;
	++next_id;
}


Mesh::~Mesh()
{
}

string Mesh::to_string()
{
	return ("ID: " + std::to_string(this->id) + " Name: " + this->name + " Vertices: " + std::to_string(this->vertices) + " Faces: " + std::to_string(this->faces) + " Scaling: " + std::to_string(this->scaling));
}