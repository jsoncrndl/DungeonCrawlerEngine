#include "free_resource_visitor.h"

namespace Engine::Game
{
	void FreeResourceVisitor::visit(PooledObject* object)
	{
		if (object->m_isFree)
		{
			m_result = object;
			object->reset();
			object->m_isFree = false;
		}
	}
	PooledObject* FreeResourceVisitor::getResult()
	{
		return m_result;
	}
}