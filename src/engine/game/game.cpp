#include "game.h"
#include "states/gs_loading.h"
#include "states/gs_level.h"

namespace Engine::Game
{
	void Game::initializeStates()
	{
		m_states[GameStateType::LOADING] = m_memory.allocate<LoadingGameState>(1);
		m_states[GameStateType::LEVEL] = m_memory.allocate<LevelGameState>(1);
	}

	Game::Game(Engine::RuntimeEngine* engine) : m_currentState(nullptr), m_nextState(GameStateType::LOADING)
	{
	}

	void Game::load()
	{
		m_memory.reserve(500000000);

		initializeStates();
		
		uint16_t numLevels = 3;

		Level* levels = m_memory.allocate<Level>(numLevels);
		m_levels = PoolArray<Level>(levels, numLevels);
	}

	void Game::update(float deltaSeconds)
	{
		m_currentState->update(deltaSeconds);
	}

	void Game::render(std::shared_ptr<Graphics::Graphics> graphics)
	{
		m_currentState->render(graphics);
	}

	void Game::quit()
	{
		m_memory.free();
	}

	GameState* Game::getState(GameStateType state)
	{
		return m_states[state];
	}
}