#include "texture.h"

namespace Engine::Graphics
{
	Texture::Texture(uint32_t texture, uint16_t width, uint16_t height) :
		m_width(width),
		m_height(height),
		m_texture(texture)
	{
	}

	const uint16_t& Texture::getWidth() const
	{
		return m_width;
	}

	const uint16_t& Texture::getHeight() const
	{
		return m_height;
	}

	const Rect Texture::getRect() const
	{
		return Rect(0, 0, getWidth(), getHeight());
	}

	// This shouldn't be used
	Texture::Texture()
	{
	}
}