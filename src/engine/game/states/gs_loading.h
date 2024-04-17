#pragma once
#include "game_state.h"

namespace Engine::Game
{
	class LoadingGameState : public GameState
	{
	public:
		virtual void initialize() override;
		virtual void update(float deltaSeconds) override;
		virtual void render(std::shared_ptr<Graphics::Graphics> graphics) override;
	};
}