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
			auto now = std::chrono::steady_clock::now();

			handleInput();
			update(deltaTime);
			render();

			auto endTime = std::chrono::steady_clock::now();
			deltaTime = std::chrono::duration_cast<std::chrono::microseconds>((endTime - now)).count() / 1000000.0f;
		}
	}

	RuntimeEngine::RuntimeEngine(Memory::Block block) :
		m_allocator(EngineAllocator{ block, "Engine Allocator" }),
		m_game(nullptr),
		m_activeRenderPipeline(nullptr),
		m_window(nullptr),
		m_assetManager(nullptr)
	{
	}

	void RuntimeEngine::initialize()
	{

#if !DCE_DEDICATED_SERVER
		initGraphics();

		m_eventDispatcher = new EventDispatcher(m_window);
#endif
	}


	void RuntimeEngine::initGraphics()
	{
#if !DCE_DEDICATED_SERVER

		m_assetManager = Factory::create<Resources::AssetManager>();
		m_assetManager->LoadEngineAssets();
		m_assetManager->LoadResources();

		m_window = Factory::create<Graphics::GameWindow>(m_allocator);
		m_graphics = Factory::create<Graphics::Graphics>(m_window);

		m_graphics->loadShaders(m_assetManager->getShaders("engine"));
		m_graphics->loadTextures(m_assetManager->getTextures("engine"));

		m_graphics->postLoad();

		m_defaultRenderPipeline = Factory::create<Graphics::RenderPipeline>();
		m_defaultRenderPipeline->initialize(m_graphics);
		m_activeRenderPipeline = m_defaultRenderPipeline;

		m_window->registerWindowEventListener(Graphics::WindowEvent::CLOSE, [this](Graphics::WindowEventData eventData) {
			quit();
			});
#endif
	}

	void RuntimeEngine::handleInput()
	{
#if !DCE_DEDICATED_SERVER
		m_eventDispatcher->handleEvents();
#endif
	}

	void RuntimeEngine::update(float deltaTime)
	{
		if (m_game != nullptr)
		{
			m_game->update(deltaTime);
		}
	}

	void RuntimeEngine::render()
	{
#if !DCE_DEDICATED_SERVER
		// Render pipeline should be part of a game
		m_activeRenderPipeline->render(m_graphics);
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

	Graphics::GameWindow* RuntimeEngine::getWindow()
	{
		return m_window;
	}

	Resources::AssetManager* RuntimeEngine::getAssetManager()
	{
		return m_assetManager;
	}

	void RuntimeEngine::loadGame(std::string path)
	{
		if (m_game != nullptr)
		{
			closeGame();
		}

		m_game = Factory::create<Game::Game>(this);
	}

	void RuntimeEngine::closeGame()
	{
		m_game->quit();
		delete m_game;
	}

	void RuntimeEngine::quit()
	{
		m_shouldQuit = true;
	}
	void RuntimeEngine::setRenderPipeline(Graphics::RenderPipeline* pipeline)
	{
#if !DCE_DEDICATED_SERVER
		if (pipeline == nullptr)
		{
			m_activeRenderPipeline = m_defaultRenderPipeline;
		}
		else
		{
			m_activeRenderPipeline = pipeline;
		}
#endif
	}

	Graphics::Graphics* RuntimeEngine::getGraphics()
	{
		return m_graphics;
	}

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