#include "game_window.h"
#include "iostream"


namespace Engine::Graphics
{
	std::shared_ptr<GameWindow> GameWindow::create()
	{
		return std::shared_ptr<GameWindow>(new GameWindow());
	}

	void GameWindow::resize(int width, int height)
	{
		SDL_SetWindowSize(m_window, width, height);
	}

	void GameWindow::setPosition(int x, int y)
	{
		SDL_SetWindowPosition(m_window, x, y);
	}

	void GameWindow::setFullscreen(bool fullscreen)
	{
		SDL_SetWindowFullscreen(m_window, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
	}

	void GameWindow::close()
	{
		SDL_DestroyWindow(m_window);
	}

	Rect GameWindow::getRect() const
	{
		return Rect(0, 0, m_width, m_height);
	}

	Rect GameWindow::getRect(uint16_t width, uint16_t height) const
	{
		// Calculate best fit rectangle with width:height ratio

		float windowRatio = static_cast<float>(m_width) / static_cast<float>(m_height);
		float innerRatio = static_cast<float>(width) / static_cast<float>(height);
		float scale = windowRatio > innerRatio ? static_cast<float>(m_height) / static_cast<float>(height) : static_cast<float>(m_width) / static_cast<float>(width);

		uint16_t rectWidth = static_cast<uint16_t>(width * scale);
		uint16_t rectHeight = static_cast<uint16_t>(height * scale);

		uint16_t widthDifference = m_width - rectWidth;
		uint16_t heightDifference = m_height - rectHeight;

		return Rect(widthDifference / 2, heightDifference / 2, rectWidth, rectHeight);
	}

	void GameWindow::handleEvent(SDL_Event e)
	{
		if (e.type == SDL_WINDOWEVENT)
		{
			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_CLOSE:
				invokeWindowEvent(WindowEvent::CLOSE);
				break;
			case SDL_WINDOWEVENT_MINIMIZED:
				invokeWindowEvent(WindowEvent::MINIMIZE);
				break;
			case SDL_WINDOWEVENT_MAXIMIZED:
				invokeWindowEvent(WindowEvent::MAXIMIZE);
				break;
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				invokeWindowEvent(WindowEvent::RESIZE, WindowEventData(e.window.data1, e.window.data2));
				break;
			case SDL_WINDOWEVENT_SHOWN:
				invokeWindowEvent(WindowEvent::SHOW);
				break;
			case SDL_WINDOWEVENT_HIDDEN:
				invokeWindowEvent(WindowEvent::HIDE);
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				invokeWindowEvent(WindowEvent::FOCUS);
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				invokeWindowEvent(WindowEvent::UNFOCUS);
				break;
			case SDL_WINDOWEVENT_MOVED:
				invokeWindowEvent(WindowEvent::MOVE);
				break;
			}
		}
	}

	void GameWindow::invokeWindowEvent(WindowEvent event)
	{
		invokeWindowEvent(event, WindowEventData(0, 0));
	}

	void GameWindow::invokeWindowEvent(WindowEvent event, WindowEventData data)
	{
		for (auto& function : m_eventCallbacks[event])
		{
			function(data);
		}
	}


	void GameWindow::registerWindowEventListener(WindowEvent event, std::function<void(const WindowEventData&)> callback)
	{
		m_eventCallbacks[event].push_back(callback);
	}

	GameWindow::GameWindow()
	{
		m_window = SDL_CreateWindow("Dungeon Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		
		m_width = 1280;
		m_height = 720;

		if (m_window == nullptr) {
			SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
			return;
		}

		registerWindowEventListener(RESIZE, [this](const WindowEventData& e) {
				m_width = static_cast<uint16_t>(e.x);
				m_height = static_cast<uint16_t>(e.y);
			}
		);
	}

	GameWindow::~GameWindow()
	{
		SDL_DestroyWindow(m_window);
	}

	WindowEventData::WindowEventData(int x, int y) : x(x), y(y)
	{
	}
}