#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <Raytracer/Accelerator.h>
#include <Raytracer/IIntegrator.h>
#include <Raytracer/Image.h>
#include <Raytracer/Ray.h>
#include <Raytracer/RayHit.h>
#include <Raytracer/Renderer.h>
#include <Raytracer/PhongIntegrator.h>
#include <Raytracer/SimpleAccelerator.h>
#include <Raytracer/SimpleRenderer.h>

#include <Raytracer/Scenes/Camera.h>
#include <Raytracer/Scenes/Light.h>
#include <Raytracer/Scenes/Material.h>
#include <Raytracer/Scenes/PointLight.h>
#include <Raytracer/Scenes/Scene.h>
#include <Raytracer/Scenes/SceneObject.h>
#include <Raytracer/Scenes/SceneObjectType.h>

#include <Raytracer/Objects/Mesh.h>
#include <Raytracer/Objects/Sphere.h>
#include <Raytracer/Objects/Triangle.h>

#ifdef RAYTRACER_USE_FOREACH
#include <Raytracer/Internal/foreach.h>
#endif // RAYTRACER_USE_FOREACH

#ifndef NULL
#define NULL 0
#endif // NULL

#endif // RAYTRACER_H
