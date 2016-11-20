#include <stdio.h>

#include <Raytracer/Raytracer.h>

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

void Image::Clear(const float3 &color)
{
	for (int i = 0; i < width * height; i++)
		pixels[i] = color;
}

int Image::GetHeight() const
{
	return height;
}

const float3 &Image::GetPixel(int x, int y) const
{
	return pixels[y * width + x];
}

const float3 *Image::GetPixels() const
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
			float3 color = pow(GetPixel(x, y), invGamma);

			unsigned char r = (unsigned char)clamp(color.x * 255.0f, 0.0f, 255.0f);
			unsigned char g = (unsigned char)clamp(color.y * 255.0f, 0.0f, 255.0f);
			unsigned char b = (unsigned char)clamp(color.z * 255.0f, 0.0f, 255.0f);

			fwrite(&b, 1, 1, file);
			fwrite(&g, 1, 1, file);
			fwrite(&r, 1, 1, file);
		}

		fwrite(padValues, 1, padding, file);
	}

	fclose(file);
}

void Image::SetPixel(int x, int y, const float3 &pixel)
{
	pixels[y * width + x] = pixel;
}

void Image::SetSize(int width, int height)
{
	delete [] pixels;
	this->width = width;
	this->height = height;
	pixels = new float3[width * height];
}
