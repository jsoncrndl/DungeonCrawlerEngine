#include "game.h"
#include "states/gs_loading.h"
#include "states/gs_level.h"

namespace Engine::Game
{
	Game::Game(Engine::RuntimeEngine* engine) : m_nextState(GameStateType::LOADING)
	{
	}

	void Game::load()
	{
		initializeStates();
	}

	void Game::update(float deltaSeconds)
	{
		
	}

#if !DCE_DEDICATED_SERVER
	void Game::render(Graphics::Graphics* graphics)
	{

	}
#endif

	void Game::quit()
	{
		
	}

	void Game::initializeStates()
	{
		loadingState.initialize();
		levelState.initialize();
	}
}