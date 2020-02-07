/*
 * Created by Thomas on 07/02/2020.
 */

#include <iostream>

#include <vector_buffer.hpp>

using namespace raytracer;

int main()
{
	const unsigned short IMAGE_WIDTH = 640;
	const unsigned short IMAGE_HEIGHT = 480;

	const vec4_type<>::vec4_t camera = vec4_type<>::load(0.0f, 1.0f, 1.0f, 0.0f);
	const vec4_type<>::vec4_t normDir = vec4_type<>::load(0.0f, 1.0f, -1.0f, 0.0f);

	const vec4_type<>::vec4_t screenPos = vec4_type<>::load();

	for (unsigned short i = 0; i < IMAGE_HEIGHT; ++i)
	{
		const float offset_y = (static_cast<float>(i) / static_cast<float>(IMAGE_HEIGHT)) - 0.5f;

		for (unsigned short j = 0; j < IMAGE_WIDTH; ++j)
		{
			const float offset_x = (static_cast<float>(j) / static_cast<float>(IMAGE_WIDTH)) - 0.5f;
		}
	}
}