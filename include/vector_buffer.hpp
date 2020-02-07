/*
 * Created by Thomas on 07/02/2020.
 */

#pragma once

#include <vector>

#include "layout.hpp"
#include "vec_4.hpp"

namespace raytracer
{
	template <typename LayoutTag>
	struct vector_buffer
	{
	};

	template <>
	struct vector_buffer<aos_layout>
	{
		std::vector<typename vec4_type<architecture::Native>::vec4_t> data;
	};

	template <>
	struct vector_buffer<soa_layout>
	{
		private:
		public:
		std::vector<typename vec4_type<architecture::Native>::vec4_t> x;
		std::vector<typename vec4_type<architecture::Native>::vec4_t> y;
		std::vector<typename vec4_type<architecture::Native>::vec4_t> z;
		std::vector<typename vec4_type<architecture::Native>::vec4_t> w;
	};
}