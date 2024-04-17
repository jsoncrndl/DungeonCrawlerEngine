#pragma once
#include "pooled_object_visitor.h"

namespace Engine::Game
{
	class ResetObjectVisitor : public PooledObjectVisitor
	{
	public:
		virtual void visit(PooledObject* object);
	};
}