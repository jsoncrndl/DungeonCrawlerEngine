#include "sprite_renderer.h"

namespace Engine::Game::ECS
{
	uint16_t SpriteRenderer::getSortOrder()
	{
		return m_sortOrder;
	}
	eastl::string SpriteRenderer::getDefaultSprite()
	{
		return m_defaultSprite;
	}


#if !DCE_DEDICATED_SERVER

	Graphics::Sprite SpriteRenderer::getSprite()
	{
		return m_sprite;
	}
	void SpriteRenderer::setSprite(const Graphics::Sprite& sprite)
	{
		m_sprite = sprite;
	}

#endif
}

