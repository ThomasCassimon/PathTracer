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
	template <architecture Architecture>
	struct vec4_type;

	template <architecture Architecture = architecture::Native>
	struct norm4_type
	{
	};

	template <>
	struct norm4_type<architecture::x86_64>
	{
		private:
		using norm4_t = __m128;

		norm4_t _;

		public:
		explicit norm4_type(const norm4_t norm) : _(norm) {}

		[[nodiscard]] static norm4_type<architecture::x86_64> load(float x, float y, float z, float w) noexcept;
	};

	template <architecture Architecture = architecture::Native>
	std::ostream& operator<<(std::ostream& stream, const norm4_type<Architecture>& vec);
}