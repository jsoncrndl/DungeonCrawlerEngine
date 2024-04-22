#include "entity.h"

namespace Engine::Game::ECS
{



	bool Entity::removeComponent(Component* component)
	{
		/*int foundIndex = -1;
		if (component->entity != this || m_components.) return false;
		else */

		return false;
	}

	void Entity::setName(std::string name)
	{
		m_name = name;
	}

	std::string Entity::getName()
	{
		return m_name;
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