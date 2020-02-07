/*
 * Created by Thomas on 07/02/2020.
 */

#pragma once

namespace raytracer
{
	enum class architecture
	{
		Aarch64,
		Arm,
		x86_64,
#if defined(__aarch64__)
		Native = Aarch64
#elif defined(__arm__)
		Native = Arm
#elif defined(__amd64__)
		Native = x86_64
#endif
	};
}