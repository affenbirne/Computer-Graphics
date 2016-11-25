#ifndef RAYTRACER_SAMPLE_H
#define RAYTRACER_SAMPLE_H

namespace Raytracer
{
	struct Sample
	{
		float x, y;

		// current path length
		int depth;

		// last flags (e.g. keeping track of last scattering event)
		int flags;
	};
}

#endif // RAYTRACER_SAMPLE_H
