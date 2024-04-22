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

	class GameState
	{
	public:
		virtual void initialize() = 0;
		virtual void enter();
		virtual void exit();
		virtual void update(float deltaTime) = 0;
		virtual void render(Graphics::Graphics* graphics) = 0;
	};
}