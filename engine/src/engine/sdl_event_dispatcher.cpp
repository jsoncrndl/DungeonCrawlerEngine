#include "sdl_event_dispatcher.h"

namespace Engine
{
	
	EventDispatcher::EventDispatcher(Graphics::GameWindow* window, Input::Input* input) :
		m_window(window), m_input(input)
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
			switch (e.type)
			{
			case SDL_WINDOWEVENT:
				m_window->handleEvent(e.window);
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				m_input->handleEvent(e.key);
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