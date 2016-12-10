#include <stdio.h>

#include <glm.hpp>

#include <Raytracer/Raytracer.h>

using namespace glm;
using namespace Raytracer;

Image::Image()
{
	width = 0;
	height = 0;
	pixels = NULL;
}

Image::Image(int width, int height)
{
	pixels = NULL;
	SetSize(width, height);
}

Image::~Image()
{
	delete[] pixels;
}

void Image::Clear(const vec3 &color)
{
	for (int i = 0; i < width * height; i++)
		pixels[i] = color;
}

const void Image::GetBGRPixel(int x, int y, float gamma, unsigned char *color) const
{
	if (color == NULL || gamma == 0)
		return;

	float invGamma = 1.0f / gamma;

	vec3 value = GetPixel(x, y);
	value = vec3(pow(value.x, invGamma), pow(value.y, invGamma), pow(value.z, invGamma));

	*color++ = (unsigned char)clamp(value.z * 255.0f, 0.0f, 255.0f);
	*color++ = (unsigned char)clamp(value.y * 255.0f, 0.0f, 255.0f);
	*color++ = (unsigned char)clamp(value.x * 255.0f, 0.0f, 255.0f);
}

int Image::GetHeight() const
{
	return height;
}

const vec3 &Image::GetPixel(int x, int y) const
{
	return pixels[y * width + x];
}

const vec3 *Image::GetPixels() const
{
	return pixels;
}

int Image::GetWidth() const
{
	return width;
}

void Image::SaveBMP(const char *fileName, float gamma) const
{
#pragma pack(push,1)
	struct Header
	{
		unsigned char bfType[2];
		unsigned int bfSize;
		unsigned short bfReserved1;
		unsigned short bfReserved2;
		unsigned int bfOffBits;
		unsigned int biSize;
		int biWidth;
		int biHeight;
		unsigned short biPlanes;
		unsigned short biBitCount;
		unsigned int biCompression;
		unsigned int biSizeImage;
		int biXPelsPerMeter;
		int biYPelsPerMeter;
		unsigned int biClrUsed;
		unsigned int biClrImportant;
	};
#pragma pack(pop)

	if (fileName == NULL || gamma == 0)
		return;

	float invGamma = 1.0f / gamma;
	int stride = (width * 3 + 3) / 4 * 4;
	int padding = stride - (width * 3);

	Header header = {
		{ 'B', 'M' }, sizeof(Header) + stride * height, 0, 0, sizeof(Header),
		40, width, height, 1, 24, 0, stride * height, 2835, 2835, 0, 0
	};
	const unsigned char padValues[3] = { 0, 0, 0};

#ifdef __STDC_WANT_SECURE_LIB__
	FILE *file = NULL;
	fopen_s(&file, fileName, "wb");
#else
	FILE *file = fopen(fileName, "wb");
#endif

	if (file == NULL)
		return;

	if (fwrite(&header, sizeof(Header), 1, file) != 1)
		return;

	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			// Apply gamma correction
			unsigned char buffer[3];
			GetBGRPixel(x, y, gamma, buffer);
			fwrite(buffer, sizeof(buffer), 1, file);
		}

		fwrite(padValues, 1, padding, file);
	}

	fclose(file);
}

void Image::SetPixel(int x, int y, const vec3 &pixel)
{
	if (pixel.r < 0 || pixel.g < 0 || pixel.b < 0)
		x += 0;
	pixels[y * width + x] = pixel;
}

void Image::SetSize(int width, int height)
{
	delete [] pixels;
	this->width = width;
	this->height = height;
	pixels = new vec3[width * height];
}
