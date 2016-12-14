#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <glm.hpp>

namespace Raytracer
{
  class Image
  {
  private:
    int width;
    int height;
    glm::vec3 *pixels;

    Image(const Image &);
    Image &operator=(const Image &);

  public:
    Image();
    Image(int width, int height);
    
    ~Image();

    void Clear(const glm::vec3 &color);

    const void GetBGRPixel(int x, int y, float gamma, unsigned char *color) const;

    /**
     * @return the height of the image
     */
    int GetHeight() const;
    
    /**
     * @return the width of the image
     */
    int GetWidth() const;

    const glm::vec3 & GetPixel(int i, int j) const;
    const glm::vec3 *GetPixels() const;

    void SaveBMP(const char *fileName, float gamma) const;
    void SetPixel(int x, int y, const glm::vec3 &pixel);

    void SetSize(int width, int height);
  };
}

#endif // RAYTRACER_IMAGE_H
