/*
 * Created by Thomas on 08/02/2020.
 */

#pragma once

#include <array>
#include <iosfwd>

#include "architecture.hpp"
#include "norm_3.hpp"

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
	struct vec3_type
	{
	};

	template <>
	struct vec3_type<architecture::x86_64>
	{
		using vec3_t = __m128;

		vec3_t _;

		vec3_type() noexcept;

		explicit vec3_type(const vec3_t vec) noexcept;
	};

	[[nodiscard]] vec3_type<architecture::x86_64> loadv(float x, float y, float z) noexcept;

	[[nodiscard]] std::array<float, 3> store(const vec3_type<architecture::x86_64>& vec) noexcept;

	[[nodiscard]] vec3_type<architecture::x86_64> add(const vec3_type<architecture::x86_64>& lhs,
													  const vec3_type<architecture::x86_64>& rhs) noexcept;

	[[nodiscard]] vec3_type<architecture::x86_64> subtract(const vec3_type<architecture::x86_64>& lhs,
														   const vec3_type<architecture::x86_64>& rhs) noexcept;

	[[nodiscard]] norm3_type<architecture::x86_64> normalize(const vec3_type<architecture::x86_64>& vec) noexcept;

	template <architecture Architecture = architecture::Native>
	std::ostream& operator<<(std::ostream& stream, const vec3_type<Architecture>& vec);
}