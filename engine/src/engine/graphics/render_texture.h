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
		uint32_t m_depthTexture;

		RenderTexture(uint32_t fbo, uint32_t colorTexture, uint32_t depthTexture, uint16_t width, uint16_t height);
	public:
		~RenderTexture();
	};
}