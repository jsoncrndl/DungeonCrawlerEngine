#pragma once

#include "input_event.h"

namespace Engine::Input
{
	class InputReceiver
	{
	public:
		virtual void receiveInput(const InputEvent& inputEvent) = 0;
	};
	
}