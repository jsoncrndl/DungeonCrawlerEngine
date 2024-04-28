#pragma once

#include "keys.h"

namespace Engine::Input
{
	enum class KeyEvent : uint8_t
	{
		KeyUp,
		KeyDown
	};

	struct InputEvent
	{
		KeyEvent type;
		Key key;
	};
}