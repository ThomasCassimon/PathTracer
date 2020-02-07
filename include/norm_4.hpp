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
	struct norm4_type
	{
	};

	template <>
	struct norm4_type<architecture::x86_64>
	{
		using norm4_t = __m128;

		[[nodiscard]] static norm4_t load(float x, float y, float z, float w) noexcept;
	};
}