#pragma once
#include "pooled_object_visitor.h"

namespace Engine::Game
{
	class FreeResourceVisitor : public PooledObjectVisitor
	{
		PooledObject* m_result = nullptr;

	public:
		void visit(PooledObject* component) override;
		PooledObject* getResult();
	};
}