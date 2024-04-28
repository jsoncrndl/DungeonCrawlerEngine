#pragma once

namespace Engine::Game::ECS
{
	class Entity;
	class Transform;

	class Component
	{
		friend class Entity;

	protected:
		Entity* m_entity;
		Transform* m_transform;
		bool m_pendingDelete;
		void markForDelete();
	
	public:
		Entity* getEntity();
		Entity* getEntity() const;
		Transform* getTransform() const;
		Transform* getTransform();
	};
}