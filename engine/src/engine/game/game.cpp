#include "game.h"
#include "states/gs_loading.h"
#include "states/gs_level.h"

namespace Engine::Game
{
	Game::Game(Engine::RuntimeEngine* engine) : m_currentState(nullptr), m_nextState(GameStateType::LOADING)
	{
	}

	void Game::load()
	{
		initializeStates();
	}

	void Game::update(float deltaSeconds)
	{
		m_currentState->update(deltaSeconds);
	}

	void Game::render(Graphics::Graphics* graphics)
	{
		m_currentState->render(graphics);
	}

	void Game::quit()
	{
		
	}

	void Game::initializeStates()
	{
		loadingState.initialize();
		levelState.initialize();
	}
}