#pragma once

#include "game_state.h"
#include "../level/level.h"

namespace Engine::Game
{
	class LevelGameState : public GameState
	{
		Level* m_activeLevel;

	public:
		void initialize() override;
		void update(float deltaTime) override;
		void render(std::shared_ptr<Graphics::Graphics> graphics) override;
	};
}