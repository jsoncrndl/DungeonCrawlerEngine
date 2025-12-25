#include "game.h"
#include "states/gs_loading.h"
#include "states/gs_level.h"
#include "engine/engine.h"
#include <iostream>
#include "game_render_pipeline.h"

namespace Engine::Game
{
	Game* Game::ActiveGame = nullptr;

	Game::Game(GameAllocator allocator, Network::ConnectionType connectionType) :
		m_nextState(GameStateType::LOADING),
		m_allocator(allocator),
		m_factory(&m_allocator),
		m_renderPipeline(m_factory.create<GameRenderPipeline>(this))
	{
		m_networkManager = m_factory.create<Network::NetworkManager>(this, connectionType);

	}

	void Game::update(float deltaSeconds)
	{

	}

	void Game::initialize()
	{
		ActiveGame = this;
		initializeStates();
		m_networkManager->start();
#if !DCE_DEDICATED_SERVER
		m_renderPipeline->initialize(RuntimeEngine::Engine.getGraphics());
#endif
	}

	void Game::quit()
	{
		// Unload assets
	}

	void Game::initializeStates()
	{
		loadingState.initialize();
		levelState.initialize();
		m_nextState = GameStateType::LOADING;
	}

	Game::GameAllocator* Game::getAllocator()
	{
		return &m_allocator;
	}

	Network::NetworkManager* Game::getNetworkManager()
	{
		return m_networkManager;
	}


#if !DCE_DEDICATED_SERVER
	void Game::render()
	{
		if (m_renderPipeline != nullptr)
		{
			m_renderPipeline->render(RuntimeEngine::Engine.getGraphics());
		}		
	}

	void Game::receiveInput(const Input::InputEvent& input)
	{
	}
#endif
}