#include "network_manager.h"
#include "../game.h"

namespace Engine::Game::Network
{
    NetworkManager::NetworkManager(Game* game, ConnectionType connectionType) : 
        m_game(game),
        m_server(nullptr),
        m_localClient(nullptr),
        m_clientAllocator(game->getAllocator()->allocate(getClientPoolSize(), alignof(NetworkClient)), "Network Client Allocator"),
        m_clientFactory(&m_clientAllocator),
        m_generalFactory(game->getAllocator()),
        m_connectionType(connectionType)
    {
        SteamDatagramErrMsg errMsg;

        if (!GameNetworkingSockets_Init(nullptr, errMsg)) {
            spdlog::error("Failed to initialize GameNetworkingSockets: {}\n", errMsg);
            // Handle initialization failure appropriately
        }

        m_pInterface = SteamNetworkingSockets();
    }

    void NetworkManager::startClient()
    {
        // Create a new client object

    }
    void NetworkManager::startServer()
    {
        SteamNetworkingIPAddr serverLocalAddr{};
        serverLocalAddr.Clear();
        uint16_t port = 7777;

        serverLocalAddr.m_port = port;
        m_server = m_generalFactory.create<NetworkServer>(m_pInterface->CreateListenSocketIP(serverLocalAddr, 0, nullptr));

        if (m_server->getSocket() == k_HSteamListenSocket_Invalid)
            spdlog::error("Failed to listen on port {}", port);

        spdlog::info("Server listening on port {}", port);
    }
    void NetworkManager::startHost()
    {
        startServer();

        HSteamNetConnection client, server;
        m_pInterface->CreateSocketPair(&client, &server, false, nullptr, nullptr);

        m_localClient = m_clientFactory.create<NetworkClient>(client);
        m_server->addClient(m_clientFactory.create<NetworkClient>(server));
    }

    void NetworkManager::start()
    {
        switch (m_connectionType)
        {
        case ConnectionType::DEDICATED_SERVER:
            startServer();
            break;
        case ConnectionType::HOST:
            startHost();
            break;
        case ConnectionType::CLIENT:
            startClient();
            break;
        }
    }

    size_t Engine::Game::Network::NetworkManager::getClientPoolSize()
    {
        return sizeof(NetworkClient) * 4;
    }

    NetworkClient* Engine::Game::Network::NetworkManager::getLocalClient() const
    {
        return m_localClient;
    }
    ConnectionType NetworkManager::getConnectionType() const
    {
        return m_connectionType;
    }
    Game* NetworkManager::getGame() const
    {
        return m_game;
    }
    bool NetworkManager::isServer() const
    {
        return m_connectionType == ConnectionType::DEDICATED_SERVER || m_connectionType == ConnectionType::HOST;
    }
    bool NetworkManager::isClient() const
    {
        return m_connectionType == ConnectionType::CLIENT || m_connectionType == ConnectionType::HOST;
    }
    bool NetworkManager::isClientOnly() const
    {
        return m_connectionType == ConnectionType::CLIENT;
    }
    void NetworkManager::connectToServer(IPAddress ip, uint16_t port, eastl::function<void(ConnectionResult)> callback)
    {
    }
}
