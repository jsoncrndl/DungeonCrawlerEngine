#pragma once
#include "../../graphics/graphics.h";


namespace Engine::Game
{
	class LoadingGameState
	{
	public:
		void initialize();
		void update(float deltaSeconds);
		void render(Graphics::Graphics* graphics);
	};
}