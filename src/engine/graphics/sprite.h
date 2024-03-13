#pragma once

#include <memory>

#include "SDL.h"
#include "../math/math_types.h"

namespace Engine::Graphics
{
	class Sprite
	{
		friend class Graphics;
		std::shared_ptr<Texture> texture;
		//RectInt m_rect;
	};
}