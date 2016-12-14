#ifndef RAYTRACER_SCENES_SCENEOBJECT_H
#define RAYTRACER_SCENES_SCENEOBJECT_H

#include <Raytracer/Scenes/SceneObjectType.h>

#include <vector>

namespace Raytracer
{
	namespace Scenes
	{
		class SceneObject
		{
		private:
			/**
			 * The parent of this object or NULL if this is a top-level object
			 */
			SceneObject *parent;

			/**
			 * The list of child objects.
			 */
			std::vector<SceneObject *> children;

			/**
			 * The transformation matrix to transform a point from the coordinate system of the
			 * parent of this object to its local coordinate system. If this object does not have
			 * a parent, this is the transformation from world coordinates into the local
			 * coordinate system.
			 */
			glm::mat4x4 transformation;

			/**
			 * The transformation matrix to transform a point from world coordinates to local
			 * coordinates.
			 */
			glm::mat4x4 globalTransformation;

			glm::mat4x4 globalToLocal;

			/**
			 * Updates the global transformation based on the current transformation. This
			 * includes child objects.
			 */
			void UpdateTransformations();

		public:
			/**
			 * Constructs a new SceneObject.
			 */
			SceneObject();

			/**
			 * Destructs a SceneObject and deletes all child objects.
			 */
			virtual ~SceneObject();

			/**
			 * Adds a new child to this object.
			 *
			 * @param child The new child object. This object becomes child's parent object. This
			 *   object takes ownership of child.
			 * @return true if the child was added successfully, false otherwise.
			 */
			bool AddChild(SceneObject *child);

			/**
			 * Retrieves a list of all children of this object.
			 *
			 * @return A list of all children of this object
			 */
			const std::vector<SceneObject *> &GetChildren() const;

			/**
			* Retrieves the position of this object in world space, i.e. the translation component
			* of the global transformation matrix.
			*
			* @return The global position of this object
			*/
			const glm::vec3 GetGlobalPosition() const;

			/**
			* Retrieves a matrix that can be used to transform coordinates from world space to
			* object space. This is the inverse of the global transformation matrix.
			*
			* @return The inverse of the global transformation matrix
			*/
			const glm::mat4x4 &GetGlobalToLocal() const;

			/**
			 * Retrieves the global transformation matrix. The global transformation matrix is used
			 * to transform coordinates from object space to world space.
			 *
			 * @return The global transformation matrix
			 */
			const glm::mat4x4 &GetGlobalTransformation() const;

			/**
			 * Retrieves the parent object of this object.
			 *
			 * @param The parent object of this object or NULL if this object has no parent
			 */
			SceneObject *GetParent() const;

			/**
			 * Retrieves the position of this object, i.e. the translation component of the
			 * transformation matrix.
			 *
			 * @return The position of the object
			 */
			const glm::vec3 GetPosition() const;

			/**
			 * Retrieves the transformation matrix. The transformation matrix is used to transform
			 * coordinates from object space to the object space of the parent object (or world
			 * space if this object has no parent).
			 *
			 * @return The transformation matrix
			 */
			const glm::mat4x4 &GetTransformation() const;

			/**
			 * Checks whether this instance is of the given type.
			 *
			 * @param type The type to check against
			 * @return true if this object is of type type, false otherwise
			 */
			virtual bool IsInstanceOf(SceneObjectType type) const = 0;
			
			/**
			 * Removes an object from the list of children. After removal, the object has no
			 * parent.
			 *
			 * @param child The child to be removed
			 */
			void RemoveChild(SceneObject *child);

			/**
			 * Sets the global transformation matrix. The global transformation matrix is used to
			 * transform coordinates from object space to world space.
			 *
			 * @param transformation The new global transformation matrix
			 */
			void SetGlobalTransformation(const glm::mat4x4 &transformation);

			/**
			 * Sets the position of this object, i.e. the translation component of the
			 * transformation matrix.
			 *
			 * @param position The new position
			 */
			void SetPosition(const glm::vec3 &position);

			/**
			 * Sets the transformation matrix. The transformation matrix is used to transform
			 * coordinates from object space to the object space of the parent object (or world
			 * space if this object has no parent).
			 *
			 * @param transformation The new transformation matrix
			 */
			void SetTransformation(const glm::mat4x4 &transformation);
		};
	}
}

#endif // RAYTRACER_SCENES_SCENEOBJECT_H
