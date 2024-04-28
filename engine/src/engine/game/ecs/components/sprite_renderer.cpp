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

	Graphics::Sprite SpriteRenderer::getSprite() const
	{
		return m_sprite;
	}
	std::shared_ptr<Graphics::Material> SpriteRenderer::getMaterial() const
	{
		return m_material;
	}
	void SpriteRenderer::setSprite(const Graphics::Sprite& sprite)
	{
		m_sprite = sprite;
	}

#endif
}

