#include "gs_level.h"

namespace Engine::Game
{
	void LevelGameState::initialize()
	{

	}

	void LevelGameState::update(float deltaTime)
	{
		//m_activeLevel->update(deltaTime);
	}

#if !DCE_DEDICATED_SERVER
	void LevelGameState::render(Graphics::Graphics*	graphics)
	{
		//m_activeLevel->render(graphics);
	}
#endif

}