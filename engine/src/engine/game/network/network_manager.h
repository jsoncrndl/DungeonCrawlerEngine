#pragma once

#include "steam/steamnetworkingsockets.h"
#include "connection_type.h"
#include "network_client.h"
#include "network_server.h"
#include "ip_address.h"
#include "connection_result.h"
#include "engine/memory/pool_allocator.h"
#include "engine/memory/permanent_allocator.h"
#include "engine/memory/factory.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace Engine::Game
{
    class Game;
}

namespace Engine::Game::Network
{

    class NetworkManager
    {
    public:
        using ClientAllocator = Memory::PoolAllocator<sizeof(NetworkClient), alignof(NetworkClient)>;
        using NetworkAllocator = Memory::PermanentAllocator;
    
    private:
        ClientAllocator m_clientAllocator;

        Memory::Factory<ClientAllocator> m_clientFactory;
        Memory::Factory<NetworkAllocator> m_generalFactory;

        Game* m_game;
        ConnectionType m_connectionType;

        NetworkServer* m_server;
        NetworkClient* m_localClient;
        
        ISteamNetworkingSockets* m_pInterface;
        // Client - NetworkClient
        //  NetworkServer Server
        //  Active level
        //  PlayerComponent playerObject
        
        // ECS::PlayerComponent m_localPlayer;

        void startClient();
        void startServer();
        void startHost();

        size_t getClientPoolSize();

    public:

        NetworkManager(Game* game, ConnectionType connectionType);

        NetworkClient* getLocalClient() const;
        ConnectionType getConnectionType() const;
        Game* getGame() const;
        
        bool isServer() const;
        bool isClient() const;
        bool isClientOnly() const;

        void connectToServer(IPAddress ip, uint16_t port, eastl::function<void(ConnectionResult)> callback);
        void start();

        // ECS::PlayerComponent 
    };
}