#pragma once
#include "pooled_object.h"


namespace Engine::Game
{
	class PooledObjectVisitor
	{
	public:
		virtual void visit(PooledObject* object) = 0;
	};
}