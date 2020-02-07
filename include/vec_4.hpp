/*
 * Created by Thomas on 07/02/2020.
 */

#pragma once

#include <array>
#include <iosfwd>

#include "architecture.hpp"

#if defined(__aarch64__)
	#error "Not Implemented"
#elif defined(__arm__)
	#error "Not Implemented"
#elif defined(__amd64__)
	#include "x86intrin.h"
#endif

namespace raytracer
{
	template <architecture Architecture = architecture::Native>
	struct vec4_type
	{
	};

	template <>
	struct vec4_type<architecture::x86_64>
	{
		using vec4_t = __m128;

		[[nodiscard]] static vec4_t load(float x, float y, float z,
										 float w) noexcept;

		[[nodiscard]] static std::array<float, 4>
		store(const vec4_t& vec) noexcept;
	};

	template <architecture Architecture = architecture::Native>
	std::ostream&
	operator<<(std::ostream& stream,
			   const typename vec4_type<Architecture>::vec4_t& vec);
}