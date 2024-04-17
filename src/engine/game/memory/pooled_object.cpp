#include "pooled_object.h"
#include "free_resource_visitor.h"

namespace Engine::Game
{
	void PooledObject::accept(PooledObjectVisitor* visitor)
	{
		visitor->visit(this);
	}
	PooledObject::~PooledObject()
	{
	}
}