#pragma once

#include "../../pooled_object.h"

namespace Engine::Game::ECS
{
	class Entity;
	class Component : public PooledObject
	{
		friend class Entity;
		Entity* entity;
		bool m_pendingDelete;

		virtual void reset() = 0;
		void markForDelete();
	};
}