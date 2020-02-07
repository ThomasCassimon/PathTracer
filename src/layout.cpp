/*
 * Created by Thomas on 07/02/2020.
 */

#include "layout.hpp"

#include <iostream>

namespace raytracer
{
	std::ostream& operator<< (std::ostream& stream, const soa_layout& soa) noexcept
	{
		stream << "raytracer::soa_layout";
		return stream;
	}

	std::ostream& operator<< (std::ostream& stream, const aos_layout& aos) noexcept
	{
		stream << "raytracer::aos_layout";
		return stream;
	}
}