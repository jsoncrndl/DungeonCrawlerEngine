#include "render_texture.h"
#include "GL/glew.h"

namespace Engine::Graphics
{
	RenderTexture::RenderTexture(uint32_t fbo, uint32_t texture, uint32_t depthTexture, uint16_t width, uint16_t height) : 
		Texture(texture, width, height), m_fbo(fbo),
		m_depthTexture(depthTexture)
	{
	}

	RenderTexture::~RenderTexture()
	{
		glDeleteTextures(1, &m_depthTexture);
		glDeleteTextures(1, &m_texture);
	}
}