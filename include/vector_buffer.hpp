/*
 * Created by Thomas on 07/02/2020.
 */

#pragma once

#include <vector>

#include "layout.hpp"
#include "vec_4.hpp"

namespace raytracer
{
	template <typename VectorType, typename LayoutTag>
	struct vector_buffer
	{
	};

	template <typename VectorType>
	struct vector_buffer<VectorType, aos_layout>
	{
		std::vector<VectorType> data;
	};

	template <typename VectorType>
	struct vector_buffer<VectorType, soa_layout>
	{
		private:
		public:
		std::vector<VectorType> x;
		std::vector<VectorType> y;
		std::vector<VectorType> z;
		std::vector<VectorType> w;
	};
}