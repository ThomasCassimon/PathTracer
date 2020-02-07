/*
 * Created by Thomas on 07/02/2020.
 */

#include <iostream>

#include <vector_buffer.hpp>

using namespace raytracer;

int main()
{
	vector_buffer<aos_layout> buf;
	buf.data.push_back(vec4_type<>::load(1.0, 2.0, 3.0, 4.0));

	std::cout << buf.data[0] << '\n';
}