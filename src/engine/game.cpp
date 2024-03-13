#include <chrono>
#include <iostream>

#include "game.h"
#include "graphics/graphics.h"

// Game has a renderer, window, and a state
// It runs the main game loop
// The renderer is the render pipeline

namespace Engine
{
	void Game::mainLoop()
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

	Game::Game()
	{
		initialize();
		mainLoop();
	}

	void Game::initialize()
	{

		initGraphics();

		m_eventDispatcher = std::make_shared<EventDispatcher>(m_window);
	}

	void Game::initGraphics()
	{
		m_window = Graphics::GameWindow::create();
		m_window->registerWindowEventListener(Graphics::WindowEvent::CLOSE, [this](Graphics::WindowEventData eventData) {
			quit();
			});

		m_graphics = std::make_shared<Graphics::Graphics>(m_window);
		m_renderPipeline = std::make_shared<Graphics::RenderPipeline>();
		m_renderPipeline->initialize(m_graphics);
	}


	void Game::loadContent()
	{
	}

	void Game::handleInput()
	{
		m_eventDispatcher->handleEvents();
	}

	void Game::update(float deltaTime)
	{
		if (deltaTime != 0) 
		{
			std::cout << 1 / deltaTime << "\n";
		}
	}

	void Game::render()
	{
		m_renderPipeline->render(m_graphics);
	}

	void Game::quit()
	{
		m_shouldQuit = true;
	}
	void Game::setRenderPipeline(std::shared_ptr<Graphics::RenderPipeline> pipeline)
	{
		m_renderPipeline = pipeline;	
	}
}