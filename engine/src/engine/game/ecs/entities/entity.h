#pragma once

#include <EASTL/vector.h>
#include "../components/component.h"
#include "../components/transform.h"
#include "../../serializable.h"

namespace Engine::Game::ECS
{
	class Entity : public Serializable
	{
		std::string m_name;
		eastl::vector<Component*> m_components;
		Transform* m_transform;
		bool m_pendingDelete;

	public:
		Component* addComponent(Component* component);
		bool removeComponent(Component* component);

		void setName(std::string name);
		std::string getName();

		template <typename T>
		T* getComponent();

		void Destroy();
	};

	template <typename T>
	T* Entity::getComponent()
	{
		return nullptr;
	}
}