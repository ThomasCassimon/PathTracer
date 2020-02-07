/*
 * Created by Thomas on 07/02/2020.
 */

#pragma once

#include <iosfwd>

namespace raytracer
{
	struct soa_layout
	{
	};

	struct aos_layout
	{
	};

	std::ostream& operator<< (std::ostream& stream, const soa_layout& soa) noexcept;
	std::ostream& operator<< (std::ostream& stream, const aos_layout& aos) noexcept;
}