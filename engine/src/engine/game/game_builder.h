#pragma once

#include "game.h"
#include "game_settings.h"
#include "network/connection_type.h"

namespace Engine::Game
{
    class GameBuilder
    {
        GameSettings m_settings;
        uint8_t m_maxLevels;
        Network::ConnectionType m_connectionType;

    public:
        GameBuilder* settings(GameSettings settings);
        GameBuilder* maxLoadedLevels(uint8_t maxLevels);
        GameBuilder* connectionType(Network::ConnectionType connectionType);
        Game* build();
    };
}