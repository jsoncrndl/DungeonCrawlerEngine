#pragma once

#include "EASTL/string.h"

namespace Engine::Game
{
    class GameSettings
    {
    public:
        eastl::string name;
        eastl::string gameID;
        eastl::string startLevel;
        uint8_t maxPlayers;
    };
}
