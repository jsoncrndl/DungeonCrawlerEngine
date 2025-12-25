#pragma once

#if !DCE_DEDICATED_SERVER
	#include "input/input_event.h"
	#include "input/input_receiver.h"
#endif

namespace Engine
{
	class GameLike
#if !DCE_DEDICATED_SERVER
		: public Input::InputReceiver
#endif
	{
	public:
		virtual void initialize() = 0;
		virtual void update(float deltaSeconds) = 0;
		virtual void quit() = 0;

#if !DCE_DEDICATED_SERVER
		virtual void receiveInput(const Input::InputEvent& input) = 0;
		virtual void render() = 0;
#endif
	};
}