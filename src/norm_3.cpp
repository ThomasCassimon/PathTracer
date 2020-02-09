/*
 * Created by Thomas on 08/02/2020.
 */

#include "norm_3.hpp"

#include "vec_3.hpp"

namespace raytracer
{
	norm3_type<architecture::x86_64>::norm3_type() noexcept : _(_mm_set_ps(0.0f, 0.0f, 0.0f, 1.0f)) {}

	norm3_type<architecture::x86_64>::norm3_type(const norm3_t norm) noexcept : _(norm) {}

	norm3_type<architecture::x86_64>::operator vec3_type<architecture::x86_64>() const noexcept
	{
		return vec3_type<architecture::x86_64> {this->_};
	}

	template <architecture Architecture>
	std::ostream& operator<<(std::ostream& stream, const norm3_type<Architecture>& norm)
	{
		stream << static_cast<vec3_type<>>(norm);
		return stream;
	}

	template std::ostream& operator<< (std::ostream& stream, const norm3_type<architecture::Native>& norm);
}