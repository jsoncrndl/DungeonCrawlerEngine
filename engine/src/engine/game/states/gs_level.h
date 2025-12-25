#pragma once

#if !DCE_DEDICATED_SERVER
	
#include "../../graphics/graphics.h"

#endif

//#include "../level/level.h"

namespace Engine::Game
{
	class Game;
	class LevelGameState
	{
		Game* game;

	public:
		void initialize();
		void update(float deltaTime);
#if !DCE_DEDICATED_SERVER

		void render(Graphics::Graphics* graphics);
#endif
	};
}