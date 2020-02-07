/*
 * Created by Thomas on 07/02/2020.
 */

#pragma once

#include <vector>

#include "layout.hpp"
#include "vec_4.hpp"

namespace raytracer
{
	template <typename LayoutTag,
			  architecture Architecture = architecture::Native>
	struct vector_buffer
	{
	};

	template <architecture Architecture>
	struct vector_buffer<aos_layout, Architecture>
	{
		std::vector<typename vec4_type<Architecture>::vec4_t> data;
	};

	template <architecture Architecture>
	struct vector_buffer<soa_layout, Architecture>
	{
		std::vector<typename vec4_type<Architecture>::vec4_t> x;
		std::vector<typename vec4_type<Architecture>::vec4_t> y;
		std::vector<typename vec4_type<Architecture>::vec4_t> z;
		std::vector<typename vec4_type<Architecture>::vec4_t> w;
	};
}