#pragma once

#include <memory>
#include "SDL.h"
#include "texture.h"

namespace Engine::Graphics
{
	class Graphics;

	/// <summary>
	/// A texture to be rendered to
	/// </summary>
	class RenderTexture : public Texture
	{
		friend class Graphics;
	
		uint32_t m_fbo;

		RenderTexture(uint32_t fbo, uint32_t texture, uint16_t width, uint16_t height);
		~RenderTexture();
	};
}