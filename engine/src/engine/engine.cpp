#include <chrono>
#include <iostream>

#include "engine.h"
#include "memory/byte_literals.h"
#include "game/game.h"

// Game has a renderer, window, and a state
// It runs the main game loop
// The renderer is the render pipeline

namespace Engine
{
	RuntimeEngine RuntimeEngine::Engine{ Memory::Block(std::malloc(100000), 100000) };

	void RuntimeEngine::mainLoop()
	{
		float deltaTime = 0;

		while (!m_shouldQuit) {
			if (m_nextGame != nullptr)
			{
				if (m_activeGame != nullptr)
				{
					closeGame();
				}

				m_activeGame = m_nextGame;
				m_nextGame = nullptr;
				m_activeGame->initialize();
			}

			if (m_activeGame == nullptr) break;
		
			auto now = std::chrono::steady_clock::now();

#if !DCE_DEDICATED_SERVER
			m_eventDispatcher->handleEvents();
#endif

			m_activeGame->update(deltaTime);

#if !DCE_DEDICATED_SERVER
			m_activeGame->render();
#endif
			auto endTime = std::chrono::steady_clock::now();
			deltaTime = std::chrono::duration_cast<std::chrono::microseconds>((endTime - now)).count() / 1000000.0f;
		}
	}

	RuntimeEngine::RuntimeEngine(Memory::Block block) :
		m_allocator(EngineAllocator{ block, "Engine Allocator" }),
		m_activeGame(nullptr),
		m_nextGame(nullptr)
#if !DCE_DEDICATED_SERVER
		,m_assetManager(nullptr),
		m_window(nullptr),
		m_eventDispatcher(nullptr),
		m_graphics(nullptr),
		m_input(nullptr)
#endif
	{
	}

	void RuntimeEngine::initialize()
	{

#if !DCE_DEDICATED_SERVER
		initGraphics();
		m_input = m_factory.create<Input::Input>();
		m_eventDispatcher = m_factory.create<EventDispatcher>(m_window, m_input);
#endif
	}

	void RuntimeEngine::initGraphics()
	{
#if !DCE_DEDICATED_SERVER

		m_assetManager = m_factory.create<Resources::AssetManager>();
		m_assetManager->LoadEngineAssets();
		m_assetManager->LoadResources();

		m_window = m_factory.create<Graphics::GameWindow>(m_allocator);
		m_graphics = m_factory.create<Graphics::Graphics>(m_window);
		m_graphics->loadTextures(m_assetManager->getTextures("engine"));
		m_graphics->loadShaders(m_assetManager->getShaders("engine"));
		//m_graphics->loadMaterials(m_assetManager->getMaterials("engine"));
		m_graphics->postLoad();

		m_window->registerWindowEventListener(Graphics::WindowEvent::CLOSE, [this](Graphics::WindowEventData eventData) {
			quit();
		});
#endif
	}

	void RuntimeEngine::start()
	{
		if (m_isStarted)
		{
			std::cout << "Engine is already started!\n";
		}
		initialize();
		mainLoop();
	}

	RuntimeEngine::EngineAllocator* RuntimeEngine::getAllocator()
	{
		return &m_allocator;
	}

	//void RuntimeEngine::loadGame(std::string path)
	//{
	//	if (m_game != nullptr)
	//	{
	//		closeGame();
	//	}

	//	m_game = Factory::create<Game::Game>(this);
	//}

	void RuntimeEngine::loadGame(GameLike* game)
	{
		m_nextGame = game;
	}

	void RuntimeEngine::closeGame()
	{
		m_activeGame->quit();
		m_activeGame = nullptr;
		// free game memory
	}

	void RuntimeEngine::quit()
	{
		m_shouldQuit = true;
	}

#if !DCE_DEDICATED_SERVER
	Graphics::GameWindow* RuntimeEngine::getWindow()
	{
		return m_window;
	}

	Resources::AssetManager* RuntimeEngine::getAssetManager()
	{
		return m_assetManager;
	}

	Graphics::Graphics* RuntimeEngine::getGraphics()
	{
		return m_graphics;
	}
#endif



	void RuntimeEngine::cleanUp()
	{
#if !DCE_DEDICATED_SERVER
		Engine.getAssetManager()->UnloadEngineAssets();
#endif
		void* memory = Engine.m_allocator.getBlock().ptr;
		Engine.~RuntimeEngine();
		free(memory);
	}
}