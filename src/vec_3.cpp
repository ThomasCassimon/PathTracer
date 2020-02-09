/*
 * Created by Thomas on 08/02/2020.
 */

#include "vec_3.hpp"

#include <cmath>
#include <cstring>

#include <iostream>

namespace raytracer
{
	vec3_type<architecture::x86_64>::vec3_type() noexcept : _(_mm_set1_ps(0.0)) {}

	vec3_type<architecture::x86_64>::vec3_type(const vec3_t vec) noexcept : _(vec) {}

	vec3_type<architecture::x86_64> loadv(float x, float y, float z) noexcept
	{
		return vec3_type<architecture::x86_64>{_mm_set_ps(0.0f, z, y, x)};
	}

	[[nodiscard]] std::array<float, 3> store(const vec3_type<architecture::x86_64>& vec) noexcept
	{
		const static __m128i mask = _mm_set_epi32(-1, -1, -1, 0);

		std::array<float, 3> data = {{0.0}};
		_mm_maskstore_ps(data.data(), mask, vec._);

		return data;
	}

	[[nodiscard]] float dot(const vec3_type<architecture::x86_64>& lhs,
							const vec3_type<architecture::x86_64>& rhs) noexcept
	{
		constexpr static int imm8 = 0xE1u;
		const vec3_type<architecture::x86_64>::vec3_t dot = _mm_dp_ps(lhs._, rhs._, imm8);

		float dp;

		_mm_store_ss(&dp, dot);

		return dp;
	}

	[[nodiscard]] float length(const vec3_type<architecture::x86_64>& vec) noexcept { return std::sqrt(dot(vec, vec)); }

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
		const vec3_type<architecture::x86_64>::vec3_t len = _mm_set1_ps(length(vec));

		return norm3_type<architecture::x86_64>{_mm_div_ps(vec._, len)};
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

	template std::ostream& operator<<(std::ostream& stream, const vec3_type<architecture::Native>& vec);
}