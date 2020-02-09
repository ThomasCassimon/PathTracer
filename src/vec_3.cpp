/*
 * Created by Thomas on 08/02/2020.
 */

#include "vec_3.hpp"

#include <cstring>

#include <iostream>

namespace raytracer
{
	vec3_type<architecture::x86_64>::vec3_type() noexcept: _(_mm_set1_ps(0.0))
	{}

	vec3_type<architecture::x86_64>::vec3_type(const vec3_t vec) noexcept: _(vec)
	{}

	vec3_type<architecture::x86_64> loadv(float x, float y, float z) noexcept
	{
		return vec3_type<architecture::x86_64>{_mm_set_ps(0.0f, z, y, x)};
	}

	[[nodiscard]] std::array<float, 3> store(const vec3_type<architecture::x86_64>& vec) noexcept
	{
		std::array<float, 4> data = {{ 0.0 }};
		_mm_store_ps(data.data(), vec._);

		std::array<float, 3> result = {{ 0.0 }};
		std::memcpy(result.data(), data.data(), sizeof(float) * 3);
		return result;
	}

	[[nodiscard]] vec3_type<architecture::x86_64> add(const vec3_type<architecture::x86_64>& lhs,
													  const vec3_type<architecture::x86_64>& rhs) noexcept
	{
		return vec3_type<architecture::x86_64>{_mm_add_ps(lhs._, rhs._)};
	}

	[[nodiscard]] vec3_type<architecture::x86_64> subtract(const vec3_type<architecture::x86_64>& lhs,
														   const vec3_type<architecture::x86_64>& rhs) noexcept
	{
		return vec3_type<architecture::x86_64>{_mm_sub_ps(lhs._, rhs._)};
	}

	[[nodiscard]] norm3_type<architecture::x86_64> normalize(const vec3_type<architecture::x86_64>& vec) noexcept
	{

	}

	template <architecture Architecture>
	std::ostream& operator<<(std::ostream& stream, const vec3_type<Architecture>& vec)
	{
		const std::array<float, 3> array = store(vec);

		char buffer[64];

		std::snprintf(buffer, sizeof(buffer), "{%.4f, %.4f, %.4f}", array[0], array[1], array[2]);

		stream << buffer;
		return stream;
	}
}