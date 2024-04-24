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

    void Level::render(Graphics::Graphics* graphics)
    {

    }

#endif
}