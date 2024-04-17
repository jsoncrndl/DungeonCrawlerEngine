#pragma once
#include <string>
#include <vector>
#include "../components/component.h"
#include "../components/transform.h"
#include "../../serializable.h"

namespace Engine::Game::ECS
{
	class Entity : public PooledObject, public Serializable
	{
		std::string m_name;
		std::vector<Component*> m_components;
		Transform* m_transform;
		bool m_pendingDelete;

	private:
		void reset();

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