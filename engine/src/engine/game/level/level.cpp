#include "level.h"
#include "../game.h"

namespace Engine::Game
{
    void Level::allocateMemory()
    {
        
    }

    Level::Level(Game* game, const char* name, Memory::Block memory) :
        m_game(game), m_allocator(memory, name)
    {
        allocateMemory();
    }

    void Level::postLoad()
    {
    }

    void Level::update(float deltaSeconds)
    {
    }

    Game* Level::getGame()
    {
        return m_game;
    }

#if !DCE_DEDICATED_SERVER

    ECS::SpriteRenderSystem* Level::getSpriteRenderSystem()
    {
        return m_spriteRenderSystem;
    }

    ECS::ParticleSystem* Level::getParticleSystem()
    {
        return m_particleSystem;
    }

    ECS::CameraSystem* Level::getCameraSystem()
    {
        return m_cameraSystem;
    }

    void Level::render(Graphics::Graphics* graphics)
    {

    }

#endif
}