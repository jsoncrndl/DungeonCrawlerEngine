#include "level.h"
#include "../game.h"

namespace Engine::Game
{
    Level::Level(Game* game, eastl::string name, Memory::Block memory) :
        m_game(game), m_allocator(memory, name.c_str())
    {
        allocateMemory();
    }

    void Level::postLoad()
    {
    }

    void Level::update(float deltaSeconds)
    {
    }

    void Level::render(Graphics::Graphics* graphics)
    {
        
    }

    Game* Level::getGame()
    {
        return m_game;
    }
}