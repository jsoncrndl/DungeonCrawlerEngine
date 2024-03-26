#pragma once

#include <memory>

#include "../math/math_types.h"
#include "texture.h"

namespace Engine::Graphics
{
	class Sprite
	{
		friend class Graphics;
		const std::shared_ptr<Texture> m_texture;
		const Rect m_rect;
		const Vector2 pivot;

	public:
		Sprite(std::shared_ptr<Texture> texture, Rect rect);

		const std::shared_ptr<Texture>& getTexture() const;
		const Rect& getRect() const;
	};

	class Pivot
	{
		static const Vector2 BOTTOM;
		static const Vector2 CENTER;
		static const Vector2 TOP;
		static const Vector2 LEFT;
		static const Vector2 RIGHT;
		static const Vector2 BOTTOM_RIGHT;
		static const Vector2 BOTTOM_LEFT;
		static const Vector2 TOP_RIGHT;
		static const Vector2 TOP_LEFT;
	};
}