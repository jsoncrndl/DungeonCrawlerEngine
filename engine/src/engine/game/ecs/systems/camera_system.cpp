#include "camera_system.h"
#include "engine/game/level/level.h"
#include "engine/game/ecs/components/transform.h"

void Engine::Game::ECS::CameraSystem::render(Graphics::Graphics* graphics)
{
	renderCamera(graphics, m_camera);
}

void Engine::Game::ECS::CameraSystem::renderCamera(Graphics::Graphics* graphics, Camera* camera)
{
	graphics->setProjectionMatrix(camera->getProjectionMatrix());
	graphics->setViewMatrix(camera->getTransform()->getMatrix());

	m_level->getSpriteRenderSystem()->render(graphics);
	m_level->getParticleSystem()->render(graphics);
}
