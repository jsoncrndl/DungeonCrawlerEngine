#pragma once

#include "component_visitor.h"

namespace Engine::ECS
{
	class FindDeletedComponentVisitor : public ComponentVisitor
	{
		Component* m_result = nullptr;

	public:
		void visit(Component* component) override;
		Component* getResult();
	};
}