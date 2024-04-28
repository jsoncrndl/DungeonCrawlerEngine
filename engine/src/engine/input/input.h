#pragma once
#include <SDL.h>
#include "input_receiver.h"

namespace Engine
{
	class EventDispatcher;
}

namespace Engine::Input
{
	/*
		Input system requirements:
			Subscribe to input events based on actions.

			Low-level operations: 
				Bind and unbind callbacks to key events. There will be down, up, and pressed events.
				The input events should be passed to a single InputReceiver that handles the memory allocation for storing calllbacks.
				All this class does is keep track of an active InputReceiver to register callbacks with and pass along inputs.

			InputContext - The current settings for input like menu, battle, world, etc...
				Contains a set of input mappings and bindings. This is set by an input system.

			InputAction - An input action is a single action with a binding. InputActions can be registered with the input system.
	*/


	class Input
	{
		friend class EventDispatcher;

		InputReceiver* m_activeInputReceiver;

		void handleEvent(SDL_KeyboardEvent event);	

	public:

		void setInputReceiver(InputReceiver* inputReceiver);
	};
}