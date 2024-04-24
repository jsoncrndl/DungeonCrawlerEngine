#pragma once

#include "game.h"
#include "eastl/string.h"
#include "network/connection_type.h"

namespace Engine::Game
{
    class GameLoader
    {
    public:
        static Game* loadGame(eastl::string filePath, Network::ConnectionType connectionType);
        //Game* loadGameFromConnection(address, port);
    };
}