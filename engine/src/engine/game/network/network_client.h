#pragma once
#include "network_connection.h"

namespace Engine::Game
{
	class Level;
	namespace ECS
	{
		class PlayerComponent;
	}
}

namespace Engine::Game::Network
{
	class NetworkServer;
	class NetworkClient
	{
		/// <summary>
		/// Server: The connection to this client
		/// Client: The client's connection to the server
		/// </summary>
		NetworkConnection m_connection;

		/// <summary>
		/// The level this client is currently in
		/// </summary>
		Level* m_level;

		/// <summary>
		/// The player component for this client
		/// </summary>
		ECS::PlayerComponent* m_player;

	public:
		NetworkClient();
		NetworkClient(const NetworkConnection& connection);

		NetworkConnection getConnection();
	};
}