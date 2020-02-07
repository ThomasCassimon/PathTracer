/*
 * Created by Thomas on 08/02/2020.
 */

#include "vec_3.hpp"

namespace raytracer
{
	vec3_type<architecture::x86_64>::vec3_type() noexcept : _(_mm_set1_ps(0.0)) {}
}