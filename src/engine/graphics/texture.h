#pragma once

#include <memory>
#include "SDL.h"
#include "../math//math_types.h"

namespace Engine::Graphics
{
	class Graphics;

	/// <summary>
	/// A texture to be rendered to
	/// </summary>
	class Texture
	{
	protected:
		friend class Graphics;
		
		uint16_t m_width;
		uint16_t m_height;

		uint32_t m_texture;

		Texture(uint32_t texture, uint16_t width, uint16_t height);
	
	public:
		uint16_t getWidth() const;
		uint16_t getHeight() const;
		Rect getRect() const;

		Texture();
	};
}