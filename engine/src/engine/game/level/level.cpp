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
#if !DCE_DEDICATED_SERVER
        m_particleSystem->update(deltaSeconds);
#endif



        // Destroy objects
        for (ECS::Entity* entity : m_entitiesToDestroy)
        {
            m_entities.remove(entity);
            // Return entity to pool
        }
        m_entitiesToDestroy.clear();

        // Add objects
        for (ECS::Entity* entity : m_entitiesToAdd)
        {
            m_entities.push_back(entity);
        }
        m_entitiesToAdd.clear();
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
#if !DCE_DEDICATED_SERVER
        
#endif
    }

    void Level::addEntity(ECS::Entity* entity)
    {
        m_entitiesToAdd.push_back(entity);
    }

#endif
}