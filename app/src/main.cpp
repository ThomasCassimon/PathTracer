/*
 * Created by Thomas on 07/02/2020.
 */

#include <chrono>
#include <iostream>
#include <random>

#include <vec_3.hpp>

using namespace raytracer;

int main()
{
	const unsigned short IMAGE_WIDTH = 640;
	const unsigned short IMAGE_HEIGHT = 480;

	const vec3_type<> camera = loadv(0.0f, 2.0f, 2.0f);
	const norm3_type<> normDir = normalize(loadv(0.0f, -1.0f, -1.0f));
	const norm3_type<> up = normalize(loadv(0.0f, 1.0f, -1.0f));

	const vec3_type<> screenPos = add(camera, static_cast<vec3_type<>>(normDir));

	for (unsigned short i = 0; i < IMAGE_HEIGHT; ++i)
	{
		const float offset_y = (static_cast<float>(i) / static_cast<float>(IMAGE_HEIGHT)) - 0.5f;

		for (unsigned short j = 0; j < IMAGE_WIDTH; ++j)
		{
			const float offset_x = (static_cast<float>(j) / static_cast<float>(IMAGE_WIDTH)) - 0.5f;
		}
	}
}