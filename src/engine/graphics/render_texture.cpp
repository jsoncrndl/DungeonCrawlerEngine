#include "render_texture.h"
#include "GL/glew.h"

namespace Engine::Graphics
{
	RenderTexture::RenderTexture(uint32_t fbo, uint32_t texture, uint16_t width, uint16_t height) : Texture(texture, width, height), m_fbo(fbo)
	{
	}

	RenderTexture::~RenderTexture()
	{
		glDeleteTextures(1, &m_texture);
	}
}