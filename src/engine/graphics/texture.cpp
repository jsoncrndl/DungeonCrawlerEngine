#include "texture.h"
#include "GL/glew.h"

namespace Engine::Graphics
{
	Texture::Texture(uint32_t texture, uint16_t width, uint16_t height) :
		m_width(width),
		m_height(height),
		m_texture(texture)
	{
	}

	uint16_t Texture::getWidth() const
	{
		return m_width;
	}

	uint16_t Texture::getHeight() const
	{
		return m_height;
	}

	Rect Texture::getRect() const
	{
		return Rect(0, 0, getWidth(), getHeight());
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_texture);
	}
}