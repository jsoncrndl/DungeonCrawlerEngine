#include "network_client.h"
#include "engine/game/ecs/components/player_component.h"


namespace Engine::Game::Network
{
    Engine::Game::Network::NetworkClient::NetworkClient() : NetworkClient(0)
    {
    }

    NetworkClient::NetworkClient(const NetworkConnection& connection) : m_level(nullptr), m_player(nullptr), m_connection(connection)
    {
    }

    NetworkConnection Engine::Game::Network::NetworkClient::getConnection()
    {
        return m_connection;
    }
}