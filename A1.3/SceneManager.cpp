#include "stdafx.h"
#include "SceneManager.h"
#include <iostream>

using namespace std;


SceneManager::SceneManager()
{
	this->meshs = {};
}

SceneManager::SceneManager(forward_list<Mesh> meshs)
{
	this->meshs = meshs;
}


SceneManager::~SceneManager()
{
}

void SceneManager::add_mesh(Mesh mesh)
{
	//implements a push_back function 
	auto before_end = this->meshs.before_begin();
	for (Mesh& mesh : this->meshs)
	{
		++before_end;
	}
	this->meshs.insert_after(before_end, mesh);
}

void SceneManager::delete_mesh(const int id)
{

	for (auto it = this->meshs.begin(); it != this->meshs.end(); ++it)
	{
		if (it->id == id)
		{
			this->meshs.remove(*it);
			break;
		}
	}
	
}
