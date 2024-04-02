#pragma once
#include "component.h"

namespace Engine::ECS
{
	class ComponentVisitor
	{
	public:
		virtual void visit(Component* component) = 0;
	};
}