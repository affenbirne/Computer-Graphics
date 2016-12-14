#ifndef RASTERIZER_SIMPLERASTERIZER_H
#define RASTERIZER_SIMPLERASTERIZER_H

#include <Raytracer/Raytracer.h>

namespace Rasterizer
{
  /**
   * Renders a scene into an image by rasterizing all triangle meshes it contains.
   */
  class SimpleRasterizer
  {
  private:
    /**
     * The image to render into
     */
    Raytracer::Image *image;

    /**
     * The ambient light color
     */
    glm::vec3 ambientLight;

    /**
     * A list of all lights in the scene
     */
    std::vector<const Raytracer::Scenes::Light *> lights;

    /**
     * A list of all meshes in the scene
     */
    std::vector<const Raytracer::Objects::Mesh *> meshes;

    /**
     * The z buffer
     */
    float *zBuffer;
    
    /**
     * The view projection matrix
     */
    glm::mat4 viewProjectionTransform;


    /**
     * Compares two triangles by their mean z values
     *
     * @param t1 The first triangle
     * @param t2 The second triangle
     * @return true if the mean z value of t1 is greater than that of z2, false otherwise
     */
    static bool CompareTriangle(const Raytracer::Objects::Triangle &t1,
                                const Raytracer::Objects::Triangle &t2);

    /**
     * Fills a horizontal span of pixels.
     *
     * @param x1 The first x coordinate
     * @param x2 The second x coordinate
     * @param y The y coordinate
     * @param z1 The z buffer value at x1
     * @param z2 The z buffer value at x2
     * @param color1 The color at x1
     * @param color2 The color at x2
     * @remarks DrawSpan sets the pixels between (x1, y) and (x2, y), including the pixel on
     *   the left side (x1 or x2, whichever is less) and excluding the pixel on the right
     *   side (x2 or x1, whichever is greater).
     */
    void DrawSpan(int x1, int x2, int y, float z1, float z2, 
                  glm::vec3 &color1, glm::vec3 &color2);
    
    /**
     * Draws a single triangle.
     *
     * @param t The triangle that has already been transformed to screen space and lit
     */
    void DrawTriangle(const Raytracer::Objects::Triangle &t);

    /**
     * Calculates the lighting for a single vertex.
     *
     * @param position The position of the vertex, in world space
     * @param normal The surface normal at the vertex position, in world space
     * @param color The diffuse material color at the vertex position
     * @return The properly modulated vertex color after applying diffuse and ambient lighting
     */
    glm::vec3 LightVertex(glm::vec4 position, glm::vec3 normal, glm::vec3 color);

    /**
     * Sorts a list of triangles according to their mean z values.
     *
     * @param triangles A list of triangles. Upon return, this list will be sorted by ascending
     *   mean z value.
     */
    void SortTriangles(std::vector<Raytracer::Objects::Triangle> &triangles);
    
    /**
     * Sorts the vertices of a single triangle in ascending order according to their y
     * coordinate.
     *
     * @param t The triangle
     * @param minIndex Will be set to the index of the vertex with the smallest y coordinate.
     * @param middleIndex Will be set to the index of the central vertex.
     * @param maxIndex Will be set to the index of the vertex with the greatest y coordinate.
     */
    void SortVertices(const Raytracer::Objects::Triangle &t, 
                      int &minIndex, int &middleIndex, int &maxIndex);

    /**
     * Transforms a triangle from model space into screen space and computes the lighting for
     * its vertices.
     *
     * @param t The triangle. Precondition: t in model space, Postcondition: t in screen space.
     * @param modelTransform the model transform matrix for vertices
     * @param modelTransformNormals the model transform matrix for normals
     */
    void TransformAndLightTriangle(Raytracer::Objects::Triangle &t, 
                                   const glm::mat4 &modelTransform,
                                   const glm::mat4 &modelTransformNormals);

    /**
     * Renders a single mesh.
     *
     * @param mesh The mesh
     */
    void RenderMesh(const Raytracer::Objects::Mesh *mesh);

    /**
     * Scans a scene object and all its children and adds any lights and meshes found to the
     * appropriate lists.
     *
     * @param object The scene object
     */
    void ScanObject(const Raytracer::Scenes::SceneObject *object);

  public:
    /**
     * Constructs a new SimpleRasterizer object.
     */
    SimpleRasterizer();

    /**
     * Rasterizes a scene into an image.
     *
     * @param image The image
     * @param scene The scene
     * @return true if the scene has been rendered successfully or false if the scene was
     *   invalid
     *
     */
    bool Render(Raytracer::Image &image, const Raytracer::Scenes::Scene &scene); 
  };
}

#endif // RASTERIZER_SIMPLERASTERIZER_H
