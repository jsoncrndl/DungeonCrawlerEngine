#pragma once
#include <array>
#include "states/game_state.h"
#include "level/level.h"


namespace Engine::Game
{
	class Game
	{
	private:
		MemoryPool m_memory;
		
		GameState* m_states;
		static const uint8_t numStates = 0;

		Level* m_levels;
		static const uint8_t numLevels = 4;



		void initializeStates();


	public:
		Game();
		GameState* getState(GameStateType state);


		// Root memory pool
		// Game states
		// List of levels
		// NetworkManager
		// Assets and resources
	};
}