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
		Graphics::GameWindow* m_window;
		Input::Input* m_input;
		void receiveEvents();

	public:
		EventDispatcher(Graphics::GameWindow* window, Input::Input* input);
		~EventDispatcher();

		void handleEvents();
	};
}