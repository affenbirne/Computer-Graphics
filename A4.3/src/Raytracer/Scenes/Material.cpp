#include <Raytracer/Raytracer.h>

using namespace Raytracer::Scenes;

Material::Material()
{
	ambient = float3(0, 0, 0);
	diffuse = float3(0.8f, 0.8f, 0.8f);
	specular = float3(1, 1, 1);
	emissive = float3(0, 0, 0);
	shininess = 4.0f;
}

float3 Material::GetAmbient()
{
	return ambient;
}

float3 Material::GetDiffuse()
{
	return diffuse;
}

float3 Material::GetEmissive()
{
	return emissive;
}

float Material::GetShininess()
{
	return shininess;
}

float3 Material::GetSpecular()
{
	return specular;
}

void Material::SetAmbient(float3 &color)
{
	ambient = color;
}

void Material::SetDiffuse(float3 &color)
{
	diffuse = color;
}

void Material::SetEmissive(float3 &color)
{
	emissive = color;
}

void Material::SetSpecular(float3 &color)
{
	specular = color;
}

void Material::SetShininess(float shininess)
{
	this->shininess = shininess;
}
