#include "sprite.h"

namespace Engine::Graphics
{
	Sprite::Sprite(std::shared_ptr<Texture> texture, Rect rect) :
		m_texture(texture),
		m_rect(rect)
	{
	}

	const std::shared_ptr<Texture>& Sprite::getTexture() const
	{
		return m_texture;
	}

	const Rect& Sprite::getRect() const
	{
		return m_rect;
	}

	const Vector2 Pivot::BOTTOM = Vector2(0.5f, 0);
	const Vector2 Pivot::TOP = Vector2(0.5f, 1);
	const Vector2 Pivot::LEFT = Vector2(1, 0.5f);
	const Vector2 Pivot::RIGHT = Vector2(0, 0.5f);
	const Vector2 Pivot::CENTER = Vector2(0.5f, 0.5f);
	const Vector2 Pivot::BOTTOM_RIGHT = Vector2(0, 0);
	const Vector2 Pivot::BOTTOM_LEFT = Vector2(1, 0);
	const Vector2 Pivot::TOP_LEFT = Vector2(1, 1);
	const Vector2 Pivot::TOP_RIGHT = Vector2(0, 1);
}