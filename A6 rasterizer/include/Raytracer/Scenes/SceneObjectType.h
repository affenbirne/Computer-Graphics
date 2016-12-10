#ifndef RAYTRACER_SCENES_SCENEOBJECTTYPE_H
#define RAYTRACER_SCENES_SCENEOBJECTTYPE_H

namespace Raytracer
{
	namespace Scenes
	{
		/**
		 * An enumeration of all types of scene objects to be used for SceneObject::InstanceOf().
		 */
		enum SceneObjectType
		{
			SceneObjectType_Scene,
			SceneObjectType_Camera,
			SceneObjectType_Light,
			SceneObjectType_PhysicalObject,
			SceneObjectType_PointLight,
			SceneObjectType_Mesh,
			SceneObjectType_Sphere
		};
	}
}

#endif // RAYTRACER_SCENES_SCENEOBJECTTYPE_H
