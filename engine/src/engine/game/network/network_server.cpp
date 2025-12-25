#include "network_server.h"
#include <steam/isteamnetworkingutils.h>
#include "engine/game/game.h"

namespace Engine::Game::Network
{


	NetworkServer::NetworkServer(Socket socket) : m_listenSocket(socket), m_clients(*Game::ActiveGame->getAllocator())
	{
	}

	void NetworkServer::update(float deltaSeconds)
	{
		// Check connection status
		// Receive any messages
	}

	NetworkServer::Socket NetworkServer::getSocket()
	{
		return m_listenSocket;
	}

	void NetworkServer::addClient(NetworkClient* client)
	{
		m_clients.insert(client->getConnection());
		m_clients[client->getConnection()] = client;
	}
}