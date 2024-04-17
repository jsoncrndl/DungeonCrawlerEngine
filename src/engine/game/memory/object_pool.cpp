#include "object_pool.h"

Engine::Game::ObjectPoolBase::ObjectPoolBase(void* location, uint16_t size) : m_objects(location), m_size(size)
{
}
