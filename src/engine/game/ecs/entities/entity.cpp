#include "entity.h"

namespace Engine::Game::ECS
{
	void Entity::reset()
	{
		m_components.clear();
		m_transform = nullptr;
		m_pendingDelete = false;
		m_name = "";
	}

	bool Entity::removeComponent(Component* component)
	{
		/*int foundIndex = -1;
		if (component->entity != this || m_components.) return false;
		else */

		return false;
	}

	Component* Entity::addComponent(Component* component)
	{
		return nullptr;
	}

	void Entity::Destroy()
	{
		m_pendingDelete = true;

		for (Component* component : m_components)
		{
			component->markForDelete();
		}
	}
}