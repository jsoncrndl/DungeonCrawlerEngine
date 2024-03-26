#include <chrono>
#include <iostream>

#include "engine.h"
#include "graphics/graphics.h"

// Game has a renderer, window, and a state
// It runs the main game loop
// The renderer is the render pipeline

namespace Engine
{
	std::shared_ptr<RuntimeEngine> RuntimeEngine::instance;

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

	RuntimeEngine::RuntimeEngine()
	{
	}

	void RuntimeEngine::initialize()
	{
		initGraphics();

		m_eventDispatcher = std::make_shared<EventDispatcher>(m_window);
	}

	void RuntimeEngine::initGraphics()
	{
		m_window = Graphics::GameWindow::create();
		m_window->registerWindowEventListener(Graphics::WindowEvent::CLOSE, [this](Graphics::WindowEventData eventData) {
			quit();
			});

		m_graphics = std::make_shared<Graphics::Graphics>(m_window);

		// Load textures and compile shaders:

		for (const auto& shaderRegistry : m_assetManager->getShaders())
		{
			m_graphics->loadShaders(shaderRegistry);
		}

		for (const auto& textureRegistry : m_assetManager->getTextures())
		{
			m_graphics->loadTextures(textureRegistry);
		}

		m_graphics->postLoad();

		m_renderPipeline = std::make_shared<Graphics::RenderPipeline>();
		m_renderPipeline->initialize(m_graphics);
	}

	void RuntimeEngine::loadContent()
	{
		m_assetManager = std::make_shared<Resources::AssetManager>();
		m_assetManager->AddProject("engine");
		m_assetManager->LoadResources();
	}

	void RuntimeEngine::handleInput()
	{
		m_eventDispatcher->handleEvents();
	}

	void RuntimeEngine::update(float deltaTime)
	{
		if (deltaTime != 0) 
		{

		}
	}

	void RuntimeEngine::render()
	{
		m_renderPipeline->render(m_graphics);
	}

	void RuntimeEngine::start()
	{
		if (m_isStarted)
		{
			std::cout << "Engine is already started!\n";
		}
		loadContent();
		initialize();
		mainLoop();
	}

	std::shared_ptr<RuntimeEngine> RuntimeEngine::create()
	{
		if (instance.get() != nullptr)
		{
			std::cout << "Engine runtime already exists!";
			return instance;
		}

		instance = std::shared_ptr<RuntimeEngine>(new RuntimeEngine());

		return instance;
	}

	std::shared_ptr<RuntimeEngine> RuntimeEngine::getInstance()
	{
		return instance;
	}

	std::shared_ptr<Graphics::GameWindow> RuntimeEngine::getWindow()
	{
		return m_window;
	}

	std::shared_ptr<Resources::AssetManager> RuntimeEngine::getAssetManager()
	{
		return m_assetManager;
	}

	void RuntimeEngine::quit()
	{
		m_shouldQuit = true;
	}
	void RuntimeEngine::setRenderPipeline(std::shared_ptr<Graphics::RenderPipeline> pipeline)
	{
		m_renderPipeline = pipeline;	
	}
}