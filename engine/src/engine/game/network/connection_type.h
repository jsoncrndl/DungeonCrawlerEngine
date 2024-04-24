#pragma once

#include <cinttypes>

namespace Engine::Game::Network
{
    enum class ConnectionType : uint8_t
    {
        DEDICATED_SERVER,
        HOST,
        CLIENT
    };
}