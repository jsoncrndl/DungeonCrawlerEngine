#include "sdl_event_dispatcher.h"

namespace Engine
{
	
	EventDispatcher::EventDispatcher(std::shared_ptr<Graphics::GameWindow> m_window) :
		m_window(m_window)
		//stopFlag(false)
		//inputThread(std::thread([this]() { receiveEvents(); }))
	{
	}

	EventDispatcher::~EventDispatcher()
	{
		//stopFlag = true;
		//inputThread.join();
	}

	void EventDispatcher::receiveEvents()
	{
		while (!stopFlag)
		{
			std::lock_guard<std::mutex> lockGuard(lock);
			
			SDL_Event e;
			while (SDL_PollEvent(&e) > 0)
			{
				bufferedEvents.push_back(e);
			}
		}
	}

	void EventDispatcher::handleEvents()
	{
		//lock.lock();
		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			if (e.type == SDL_WINDOWEVENT)
			{
				m_window->handleEvent(e);
			}
		}

		/*for (SDL_Event& event : bufferedEvents)
		{
			if (event.type == SDL_WINDOWEVENT)
			{
				m_window->handleEvent(event);
			}
		}*/
		//bufferedEvents.clear();

		//lock.unlock();
	}
}