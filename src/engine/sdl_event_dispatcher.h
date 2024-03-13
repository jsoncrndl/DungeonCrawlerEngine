#pragma once
#include <memory>
#include <thread>
#include <mutex>
#include <vector>

#include "graphics/game_window.h"
#include "input/input.h"

namespace Engine
{
	class EventDispatcher
	{
		std::shared_ptr<Graphics::GameWindow> m_window;

		std::mutex lock;
		std::vector<SDL_Event> bufferedEvents;
		std::thread inputThread;

		bool stopFlag;

		void receiveEvents();

	public:
		EventDispatcher(std::shared_ptr<Graphics::GameWindow> m_window);
		~EventDispatcher();

		void handleEvents();
	};
}