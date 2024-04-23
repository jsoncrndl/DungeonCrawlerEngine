#pragma once
#include <stdint.h>
#include <memory>

#include "../../graphics/graphics.h"

namespace Engine::Game
{
	enum class GameStateType : uint8_t
	{
		LOADING = 0,
		LEVEL = 1
	};
}