#define RAYTRACER_USE_FOREACH
#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer::Scenes;

SceneObject::SceneObject()
{
	parent = NULL;
	SetTransformation(mat4x4(1.0f));
}

SceneObject::~SceneObject()
{
	foreach (SceneObject *, child, children)
		delete *child;
}

bool SceneObject::AddChild(SceneObject *child)
{
	if (child == NULL)
		return false;

	if (child->parent == this)
		return true;

	if (child->parent != NULL)
		child->parent->RemoveChild(child);

	child->parent = this;
	children.push_back(child);
	
	child->UpdateTransformations();

	return true;
}

const std::vector<SceneObject *> &SceneObject::GetChildren() const
{
	return children;
}

const mat4x4 &SceneObject::GetGlobalToLocal() const
{
	return globalToLocal;
}

const mat4x4 &SceneObject::GetGlobalTransformation() const
{
	return globalTransformation;
}

SceneObject *SceneObject::GetParent() const
{
	return parent;
}

const vec3 SceneObject::GetPosition() const
{
	return vec3(transformation[3]);
}

const mat4x4 &SceneObject::GetTransformation() const
{
	return transformation;
}

void SceneObject::RemoveChild(SceneObject *child)
{
	if (child == NULL || child->parent != this)
		return;

	child->parent = NULL;

	foreach (SceneObject *, it, children)
	{
		if (*it == child)
		{
			children.erase(it);
			return;
		}
	}
}

void SceneObject::SetGlobalTransformation(const mat4x4 &transformation)
{
	if (parent == NULL)
		this->transformation = transformation;
	else
		this->transformation = inverse(parent->globalTransformation) * transformation;

	UpdateTransformations();
}

void SceneObject::SetPosition(const vec3 &position)
{
	transformation[3] = vec4(position, 1.0f);
	UpdateTransformations();
}

void SceneObject::SetTransformation(const mat4x4 &transformation)
{
	this->transformation = transformation;
	UpdateTransformations();
}

void SceneObject::UpdateTransformations()
{
	if (parent == NULL)
	{
		// This is a top-level object.
		globalTransformation = transformation;
	}
	else
	{
		// This object is embedded in a parent coordinate system.
		globalTransformation = parent->globalTransformation * transformation;
	}

	globalToLocal = inverse(globalTransformation);

	// Update child transformations
	foreach (SceneObject *, child, children)
		(*child)->UpdateTransformations();
}
