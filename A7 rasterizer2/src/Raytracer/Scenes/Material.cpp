#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer::Scenes;

Material::Material()
{
	ambient = vec3(0, 0, 0);
	diffuse = vec3(0.8f, 0.8f, 0.8f);
	specular = vec3(1, 1, 1);
	emissive = vec3(0, 0, 0);
	shininess = 4.0f;
}

vec3 Material::GetAmbient()
{
	return ambient;
}

vec3 Material::GetDiffuse()
{
	return diffuse;
}

vec3 Material::GetEmissive()
{
	return emissive;
}

float Material::GetShininess()
{
	return shininess;
}

vec3 Material::GetSpecular()
{
	return specular;
}

void Material::SetAmbient(vec3 &color)
{
	ambient = color;
}

void Material::SetDiffuse(vec3 &color)
{
	diffuse = color;
}

void Material::SetEmissive(vec3 &color)
{
	emissive = color;
}

void Material::SetSpecular(vec3 &color)
{
	specular = color;
}

void Material::SetShininess(float shininess)
{
	this->shininess = shininess;
}
