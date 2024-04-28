#include "component.h"

namespace Engine::Game::ECS
{
    void ECS::Component::markForDelete()
    {
        m_pendingDelete = true;
    }
    Entity* Component::getEntity()
    {
        return m_entity;
    }
    Entity* Component::getEntity() const
    {
        return m_entity;
    }
    Transform* Component::getTransform() const
    {
        return m_transform;
    }
    Transform* Component::getTransform()
    {
        return m_transform;
    }
}