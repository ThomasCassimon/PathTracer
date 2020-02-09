/*
 * @author thomas
 * @date 2/9/20.
 */

#pragma once

#include <array>
#include <iosfwd>

#include <stb_image_write.h>

namespace raytracer
{
	template <std::size_t W, std::size_t H, std::size_t N = 3>
	class frame_buffer
	{
		private:
			std::array<std::uint8_t, W * H * N>	buffer = {{ 0 }};

		public:
			constexpr frame_buffer() noexcept = default;

			void save(const std::string_view& filename) const;
	};

	template<std::size_t W, std::size_t H, std::size_t N>
	void frame_buffer<W, H, N>::save(const std::string_view& filename) const
	{
		stbi_write_png(filename.data(), W, H, N, this->buffer.data(), 0);
	}
}
