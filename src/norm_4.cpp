/*
 * Created by Thomas on 07/02/2020.
 */

#include "norm_4.hpp"

#include "vec_4.hpp"

namespace raytracer
{
	norm4_type<architecture::x86_64> norm4_type<architecture::x86_64>::load(float x, float y, float z, float w) noexcept
	{
		return vec4_type<architecture::x86_64>::normalize(vec4_type<architecture::x86_64>::load(x, y, z, w));
	}

	template <architecture Architecture>
	std::ostream& operator<<(std::ostream& stream, const norm4_type<Architecture>& vec)
	{
		stream << vec4_type{vec._};
		return stream;
	}
}