/*
 * Created by Thomas on 08/02/2020.
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
	template <architecture Architecture>
	struct vec3_type;

	template <architecture Architecture = architecture::Native>
	struct norm3_type
	{
	};

	template <>
	struct norm3_type<architecture::x86_64>
	{
		using norm3_t = __m128;

		norm3_t _;

		norm3_type() noexcept;

		explicit norm3_type(const norm3_t norm) noexcept;

		[[nodiscard]] explicit operator vec3_type<architecture::x86_64>() const noexcept;
	};

	[[nodiscard]] norm3_type<architecture::x86_64> loadn(float x, float y, float z, float w) noexcept;

	template <architecture Architecture = architecture::Native>
	std::ostream& operator<<(std::ostream& stream, const norm3_type<Architecture>& norm);
}