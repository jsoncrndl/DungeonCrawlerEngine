#pragma once
#include <memory>

namespace Engine::Game::ECS
{
	class System
	{
	public:
		virtual void update(float deltaSeconds) = 0;
		virtual void render() = 0;
	};
}