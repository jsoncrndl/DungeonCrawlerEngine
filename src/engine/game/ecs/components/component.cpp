#include "component.h"

namespace Engine::Game::ECS
{
    void ECS::Component::markForDelete()
    {
        m_pendingDelete = true;
    }
}