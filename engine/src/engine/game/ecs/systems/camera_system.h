#pragma once
#include <engine/game/ecs/components/camera.h>
#include <engine/graphics/graphics.h>

namespace Engine::Game
{
	class Level;
}

namespace Engine::Game::ECS
{
	class CameraSystem
	{
		Level* m_level;
		Camera* m_camera;

	public:
		void render(Graphics::Graphics* graphics);
		void renderCamera(Graphics::Graphics* graphics, Camera* camera);
	};
}