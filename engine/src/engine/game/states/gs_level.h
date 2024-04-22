#pragma once
#include "../../graphics/graphics.h";

//#include "../level/level.h"

namespace Engine::Game
{
	class LevelGameState
	{
		//Level* m_activeLevel;

	public:
		void initialize();
		void update(float deltaTime);
		void render(Graphics::Graphics* graphics);
	};
}