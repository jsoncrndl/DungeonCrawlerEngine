#include "gs_level.h"

namespace Engine::Game
{
	void LevelGameState::initialize()
	{

	}

	void LevelGameState::update(float deltaTime)
	{
		m_activeLevel->update(deltaTime);
	}

	void LevelGameState::render(std::shared_ptr<Graphics::Graphics>	graphics)
	{
		m_activeLevel->render(graphics);
	}
}