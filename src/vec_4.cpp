/*
 * Created by Thomas on 07/02/2020.
 */

#include "vec_4.hpp"

#include <cstdio>
#include <iostream>

namespace raytracer
{
	vec4_type<architecture::x86_64>::vec4_t
	vec4_type<architecture::x86_64>::load(float x, float y, float z,
										  float w) noexcept
	{
		return _mm_set_ps(w, z, y, x);
	}

	std::array<float, 4> vec4_type<architecture::x86_64>::store(
		const vec4_type<architecture::x86_64>::vec4_t& vec) noexcept
	{
		std::array<float, 4> data = {{0.0}};
		_mm_store_ps(data.data(), vec);
		return data;
	}

	template <architecture Architecture>
	std::ostream&
	operator<<(std::ostream& stream,
			   const typename vec4_type<Architecture>::vec4_t& vec)
	{
		const std::array<float, 4> array = vec4_type<Architecture>::store(vec);

		char buffer[64];

		std::snprintf(buffer, sizeof(buffer), "{%.4f, %.4f, %.4f, %.4f}",
					  array[0], array[1], array[2], array[3]);

		stream << buffer;
		return stream;
	}

	template std::ostream&
	operator<<(std::ostream& stream,
			   const typename vec4_type<architecture::Native>::vec4_t& vec);
}