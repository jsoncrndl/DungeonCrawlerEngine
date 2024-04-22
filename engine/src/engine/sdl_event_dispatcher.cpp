#include "sdl_event_dispatcher.h"

namespace Engine
{
	
	EventDispatcher::EventDispatcher(Graphics::GameWindow* m_window) :
		m_window(m_window)
	{
	}

	EventDispatcher::~EventDispatcher()
	{
		//stopFlag = true;
		//inputThread.join();
	}

	void EventDispatcher::receiveEvents()
	{

		//	//std::lock_guard<std::mutex> lockGuard(lock);
		////	
		//SDL_Event e;
		//while (SDL_PollEvent(&e) > 0)
		//{
		//	bufferedEvents.push_back(e);
		//}
		
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