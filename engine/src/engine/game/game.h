#pragma once
#include <array>
#include "states/game_state.h"
#include "states/gs_loading.h"
#include "states/gs_level.h"
//#include "level/level.h"

namespace Engine::Game
{
	class Engine::RuntimeEngine;

	class Game
	{
	private:		
		// States
		LoadingGameState loadingState;
		LevelGameState levelState;

		GameState* m_currentState;
		GameStateType m_nextState;
		RuntimeEngine* engine;

		void initializeStates();

	public:
		Game(Engine::RuntimeEngine* engine);

		void load();
		void update(float deltaSeconds);
		void render(Graphics::Graphics* graphics);

		void quit();

		// NetworkManager
		// Assets and resources
	};
}