#include "level.h"
#include "../game.h"

namespace Engine::Game
{
    void Level::allocateEntities(uint16_t maxAmount)
    {
    
        ECS::Entity* poolData = m_memory.allocate<ECS::Entity>(maxAmount);
        ObjectPool<ECS::Entity>* pool = m_memory.allocate<ObjectPool<ECS::Entity>>(1);
        m_entityPool = new(pool) ObjectPool<ECS::Entity>(poolData, maxAmount);
    }

    Level::Level(Game* game, MemoryPool memory) :
        m_game(game), 
        m_memory(MemoryPool(memory))
    {
        allocateMemory();
    }

    void Level::postLoad()
    {
    }

    void Level::update(float deltaSeconds)
    {
    }

    void Level::render(std::shared_ptr<Graphics::Graphics> graphics)
    {
        
    }

    void Level::allocateMemory()
    {
        m_memory.reserve(10000);

        allocateEntities(500);
        allocateComponent<ECS::Transform>(100);
    }

    ObjectPoolBase* Level::getComponentPool(std::string type)
    {
        rttr::type poolType = rttr::type::get_by_name(type);

        if (m_componentPools.count(poolType) == 0)
        {
            return nullptr;
        }

        return m_componentPools[poolType];
    }

    ObjectPool<ECS::Entity>* Level::getEntityPool()
    {
        return m_entityPool;
    }

    Game* Level::getGame()
    {
        return m_game;
    }

    void Level::reset()
    {
        // Reset all the entities, components, and systems
    }
}