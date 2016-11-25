#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

namespace Raytracer
{
	class Image
	{
	private:
		int width;
		int height;
		float3 *pixels;

		Image(const Image &);
		Image &operator=(const Image &);

	public:
		Image();
		Image(int width, int height);
		
		~Image();

		void Clear(const float3 &color);

		int GetHeight() const;

		const float3 & GetPixel(int i, int j) const;

		const float3 *GetPixels() const;

		int GetWidth() const;
		void SaveBMP(const char *fileName, float gamma) const;
		void SetPixel(int x, int y, const float3 &pixel);

		void SetSize(int width, int height);
	};
}

#endif // RAYTRACER_IMAGE_H
