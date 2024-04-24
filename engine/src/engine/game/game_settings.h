#pragma once

#include "EASTL/string.h"

namespace Engine::Game
{
    class GameSettings
    {
        eastl::string name;
        eastl::string game_id;
        uint8_t maxPlayers;
        uint8_t maxLoadedLevels;
        eastl::string startLevel;
    };
}
