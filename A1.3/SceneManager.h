#pragma once
#include "Mesh.h"
#include <forward_list>

bool operator==(Mesh const& lmesh, Mesh const& rmesh);

class SceneManager
{
public:
	SceneManager();
	SceneManager(std::forward_list<Mesh> meshs);
	~SceneManager();

	std::forward_list<Mesh> meshs;
	void add_mesh(Mesh mesh);
	void delete_mesh(int id);

};

