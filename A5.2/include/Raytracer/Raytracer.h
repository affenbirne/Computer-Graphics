#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <Raytracer/IAccelerator.h>
#include <Raytracer/IIntegrator.h>
#include <Raytracer/Image.h>
#include <Raytracer/Ray.h>
#include <Raytracer/RayHit.h>
#include <Raytracer/Renderer.h>
#include <Raytracer/PhongIntegrator.h>
#include <Raytracer/SimpleAccelerator.h>
#include <Raytracer/SimpleRenderer.h>

#include <Raytracer/Scenes/Camera.h>
#include <Raytracer/Scenes/ILight.h>
#include <Raytracer/Scenes/IPrimitive.h>
#include <Raytracer/Scenes/Material.h>
#include <Raytracer/Scenes/PointLight.h>
#include <Raytracer/Scenes/Scene.h>

#include <Raytracer/Objects/Sphere.h>

#ifndef NULL
#define NULL 0
#endif // NULL

#endif // RAYTRACER_H
