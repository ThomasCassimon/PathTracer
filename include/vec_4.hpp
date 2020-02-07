/*
 * Created by Thomas on 07/02/2020.
 */

#pragma once

#include <array>
#include <iosfwd>

#include "architecture.hpp"
#include "norm_4.hpp"

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

		vec4_t _;

		vec4_type() noexcept;

		explicit vec4_type(const vec4_t vec) : _(vec) {}
	};

	[[nodiscard]] vec4_type<architecture::x86_64> loadv(float x, float y, float z, float w) noexcept;

	[[nodiscard]] std::array<float, 4> store(const vec4_type<architecture::x86_64>& vec) noexcept;

	[[nodiscard]] vec4_type<architecture::x86_64> add(const vec4_type<architecture::x86_64>& lhs,
													  const vec4_type<architecture::x86_64>& rhs) noexcept;

	[[nodiscard]] vec4_type<architecture::x86_64> subtract(const vec4_type<architecture::x86_64>& lhs,
														   const vec4_type<architecture::x86_64>& rhs) noexcept;

	[[nodiscard]] norm4_type<architecture::x86_64> normalize(const vec4_type<architecture::x86_64>& vec) noexcept;

	template <architecture Architecture = architecture::Native>
	std::ostream& operator<<(std::ostream& stream, const vec4_type<Architecture>& vec);
}