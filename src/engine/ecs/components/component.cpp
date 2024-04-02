#include "component.h"
#include "component_visitor.h"

namespace Engine::ECS
{
	void Component::accept(ComponentVisitor& visitor)
	{
		visitor.visit(this);
	}
}