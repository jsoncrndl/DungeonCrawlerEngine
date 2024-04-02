#include "find_deleted_component_visitor.h"

namespace Engine::ECS
{
	void FindDeletedComponentVisitor::visit(Component* component)
	{
		if (component->m_isDeleted)
		{
			m_result = component;
			component->reset();
			component->m_isDeleted = false;
		}
	}
	Component* FindDeletedComponentVisitor::getResult()
	{
		return m_result;
	}
}