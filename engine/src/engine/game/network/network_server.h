#pragma once

#include <EASTL/vector.h>
#include "EASTL/unordered_map.h"
#include "spdlog/spdlog.h"
#include "engine/game/network/network_client.h"
#include "steam/steamnetworkingtypes.h"
#include "steam/isteamnetworkingsockets.h"
#include "engine/memory/permanent_allocator.h"

namespace Engine::Game::Network
{
    class NetworkServer
    {
    public:
        using Socket = HSteamListenSocket;
    private:
        Socket m_listenSocket;

        using ConnectionMap = eastl::unordered_map<NetworkConnection, NetworkClient*, eastl::hash<NetworkConnection>, eastl::equal_to<NetworkConnection>, Memory::PermanentAllocator>;
        ConnectionMap m_clients;

    public:
        NetworkServer(Socket m_listenSocket);

        void update(float deltaSeconds);
        Socket getSocket();

        /// <summary>
        /// Add an already connected client to the server. Used to create a host client
        /// </summary>
        void addClient(NetworkClient* client);
    };
}