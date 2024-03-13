#include "render_texture.h"

namespace Engine::Graphics
{
	RenderTexture::RenderTexture(uint32_t fbo, uint32_t texture, uint16_t width, uint16_t height) : Texture(texture, width, height), m_fbo(fbo)
	{
	}
}