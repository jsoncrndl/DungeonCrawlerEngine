#pragma once
#include <array>
#include "states/game_state.h"
#include "level/level.h"
#include "memory/pool_array.h"


namespace Engine {
	class RuntimeEngine;
}

namespace Engine::Game
{
	

	class Game
	{
	private:
		MemoryPool m_memory;
		
		std::unordered_map<GameStateType, GameState*> m_states;
		PoolArray<Level> m_levels;

		GameState* m_currentState;
		GameStateType m_nextState;
		RuntimeEngine* engine;

		void initializeStates();
		GameState* getState(GameStateType state);

	public:
		Game(Engine::RuntimeEngine* engine);

		void load();
		void update(float deltaSeconds);
		void render(std::shared_ptr<Graphics::Graphics> graphics);

		void quit();

		// NetworkManager
		// Assets and resources
	};
}