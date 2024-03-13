#pragma once

#include "SDL.h"
#include "../math/math_types.h"

namespace Engine::Graphics
{
	class Sprite
	{
		friend class Graphics;
		Texture texture;
		//RectInt m_rect;
	};
}