/*
 * Created by Thomas on 07/02/2020.
 */

#include <chrono>
#include <iostream>
#include <random>

#include <vector_buffer.hpp>

using namespace raytracer;

void performance()
{
	const std::size_t SIZE = 10000000;

	vector_buffer<vec4_type<>, aos_layout> buffer;

	buffer.data.push_back(loadv(1.0, 2.0, 3.0, 4.0));

	std::cout << normalize(buffer.data.front()) << '\n';

	std::random_device dev;
	std::uniform_real_distribution<float> dist;

	for (unsigned int i = 0; i < (SIZE - 1); ++i)
	{
		buffer.data.push_back(loadv(dist(dev), dist(dev), dist(dev), dist(dev)));
	}

	vector_buffer<norm4_type<>, aos_layout> resultBuffer;
	resultBuffer.data.resize(buffer.data.size());
	const unsigned int size = buffer.data.size();
	unsigned int i = 0;

	auto start = std::chrono::high_resolution_clock::now();

	for (; i < size; ++i)
	{
		resultBuffer.data[i] = normalize(buffer.data[i]);
	}

	auto end = std::chrono::high_resolution_clock::now();

	const unsigned long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	std::cout << "Normalizing " << resultBuffer.data.size() << " 4-element vectors took "
			  << static_cast<double>(duration) / 1000000.0 << "s\n";
}

int main()
{
	// performance();

	const unsigned short IMAGE_WIDTH = 640;
	const unsigned short IMAGE_HEIGHT = 480;

	const vec4_type<> camera = loadv(0.0f, 1.0f, 1.0f, 0.0f);
	const norm4_type<> normDir = normalize(loadv(0.0f, 1.0f, -1.0f, 0.0f));

	const vec4_type<> screenPos = add(camera, static_cast<vec4_type<>>(normDir));

	for (unsigned short i = 0; i < IMAGE_HEIGHT; ++i)
	{
		const float offset_y = (static_cast<float>(i) / static_cast<float>(IMAGE_HEIGHT)) - 0.5f;

		for (unsigned short j = 0; j < IMAGE_WIDTH; ++j)
		{
			const float offset_x = (static_cast<float>(j) / static_cast<float>(IMAGE_WIDTH)) - 0.5f;
		}
	}
}