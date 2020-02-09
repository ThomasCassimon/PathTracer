/*
 * Created by Thomas on 07/02/2020.
 */

#include "vec_4.hpp"

#include <cstdio>
#include <iostream>

namespace raytracer
{
	vec4_type<architecture::x86_64>::vec4_type() noexcept : _(_mm_set1_ps(0.0))
	{}

	vec4_type<architecture::x86_64>::vec4_type(const vec4_t vec) noexcept: _(vec)
	{}

	vec4_type<architecture::x86_64> loadv(float x, float y, float z, float w) noexcept
	{
		return vec4_type<architecture::x86_64>{_mm_set_ps(w, z, y, x)};
	}

	std::array<float, 4> store(const vec4_type<architecture::x86_64>& vec) noexcept
	{
		std::array<float, 4> data = {{0.0}};
		_mm_store_ps(data.data(), vec._);
		return data;
	}

	vec4_type<architecture::x86_64> add(const vec4_type<architecture::x86_64>& lhs,
										const vec4_type<architecture::x86_64>& rhs) noexcept
	{
		return vec4_type<architecture::x86_64>{_mm_add_ps(lhs._, rhs._)};
	}

	vec4_type<architecture::x86_64> subtract(const vec4_type<architecture::x86_64>& lhs,
											 const vec4_type<architecture::x86_64>& rhs) noexcept
	{
		return vec4_type<architecture::x86_64>{_mm_sub_ps(lhs._, rhs._)};
	}

	norm4_type<architecture::x86_64> normalize(const vec4_type<architecture::x86_64>& vec) noexcept
	{
		const vec4_type<architecture::x86_64>::vec4_t squared = _mm_mul_ps(vec._, vec._);

		// Version 1 (2x hadd; Latency: 40 Cycles)
		// Fastest version according to profiling data
		const vec4_type<architecture::x86_64>::vec4_t acc1 = _mm_hadd_ps(squared, squared);
		const vec4_type<architecture::x86_64>::vec4_t sum = _mm_hadd_ps(acc1, acc1);

		// Version 2 (1x shuffle, 1x hadd; 1x add, Latency: 39 cycles)
		/*
		const vec4_type<architecture::x86_64>::vec4_t perm = _mm_permute_ps (squared, _MM_PERM_BADC);
		const vec4_type<architecture::x86_64>::vec4_t acc1 = _mm_add_ps(squared, perm);
		const vec4_type<architecture::x86_64>::vec4_t sum = _mm_hadd_ps(acc1, acc1);
		 */

		// Version 3 (3x shuffle, 3x add, Latency: 39 cycles)
		/*
		const vec4_type<architecture::x86_64>::vec4_t perm0 = _mm_permute_ps(squared, _MM_PERM_CBAD);
		const vec4_type<architecture::x86_64>::vec4_t perm1 = _mm_permute_ps(squared, _MM_PERM_BADC);
		const vec4_type<architecture::x86_64>::vec4_t perm2 = _mm_permute_ps(squared, _MM_PERM_ADCB);
		const vec4_type<architecture::x86_64>::vec4_t acc1 = _mm_add_ps(squared, perm0);
		const vec4_type<architecture::x86_64>::vec4_t acc2 = _mm_add_ps(perm1, perm2);
		const vec4_type<architecture::x86_64>::vec4_t sum = _mm_add_ps(acc1, acc2);
		 */

		const vec4_type<architecture::x86_64>::vec4_t sqrt = _mm_sqrt_ps(sum);

		return norm4_type<architecture::x86_64>{_mm_div_ps(vec._, sqrt)};
	}

	template<architecture Architecture>
	std::ostream& operator<<(std::ostream& stream, const vec4_type<Architecture>& vec)
	{
		const std::array<float, 4> array = store(vec);

		char buffer[64];

		std::snprintf(buffer, sizeof(buffer), "{%.4f, %.4f, %.4f, %.4f}", array[0], array[1], array[2], array[3]);

		stream << buffer;
		return stream;
	}

	template std::ostream& operator<<(std::ostream& stream, const vec4_type<architecture::Native>& vec);
}