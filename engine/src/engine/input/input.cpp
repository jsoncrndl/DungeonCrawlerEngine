#include "input.h"
#include "input_event.h"

namespace Engine::Input
{
	void Input::handleEvent(SDL_KeyboardEvent event)
	{
		InputEvent receivedEvent;
		receivedEvent.type = event.type == SDL_KEYDOWN ? KeyEvent::KeyDown : KeyEvent::KeyUp;
		receivedEvent.key = static_cast<Key>(event.keysym.sym);

		if (event.repeat == 0 && m_activeInputReceiver != nullptr)
		{
			m_activeInputReceiver->receiveInput(receivedEvent);
		}
	}

	void Input::setInputReceiver(InputReceiver* inputReceiver)
	{
		m_activeInputReceiver = inputReceiver;
	}
}