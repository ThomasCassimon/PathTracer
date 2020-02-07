/*
 * Created by Thomas on 07/02/2020.
 */

#include "norm_4.hpp"

#include "vec_4.hpp"

namespace raytracer
{
	norm4_type<architecture::x86_64>::norm4_type() noexcept : _(_mm_set_ps(0.0, 0.0, 0.0, 1.0)) {}

	norm4_type<architecture::x86_64>::norm4_type(const norm4_t norm) noexcept : _(norm) {}

	norm4_type<architecture::x86_64>::operator vec4_type<architecture::x86_64>() const noexcept
	{
		return vec4_type<architecture::x86_64>{this->_};
	}

	norm4_type<architecture::x86_64> loadn(float x, float y, float z, float w) noexcept
	{
		return normalize(loadv(x, y, z, w));
	}

	template <architecture Architecture>
	std::ostream& operator<<(std::ostream& stream, const norm4_type<Architecture>& norm)
	{
		stream << static_cast<vec4_type<>>(norm);
		return stream;
	}

	template std::ostream& operator<<(std::ostream& stream, const norm4_type<architecture::Native>& norm);
}