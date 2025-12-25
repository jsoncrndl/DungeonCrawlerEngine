#pragma once

#if !DCE_DEDICATED_SERVER

#include "engine/graphics/graphics.h"

#endif

namespace Engine::Game
{
	class LoadingGameState
	{
	public:
		void initialize();
		void update(float deltaSeconds);

#if !DCE_DEDICATED_SERVER
		void render(Graphics::Graphics* graphics);
#endif
	};
}