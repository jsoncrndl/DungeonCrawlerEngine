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

		GameStateType m_nextState;
		Engine::RuntimeEngine* engine;

		void initializeStates();

	public:
		Game(Engine::RuntimeEngine* engine);

		void load();
		void update(float deltaSeconds);

		void quit();

		// NetworkManager
		// Assets and resources

#if !DCE_DEDICATED_SERVER
		void render(Graphics::Graphics* graphics);
#endif

	};
}