#pragma once

namespace Engine::Game::ECS
{
	class Entity;
	class Component
	{
		friend class Entity;
		Entity* entity;
		bool m_pendingDelete;
		void markForDelete();
	};
}