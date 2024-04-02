#pragma once

namespace Engine::ECS
{
	class ComponentVisitor;

	class Component
	{
		friend class FindDeletedComponentVisitor;

		bool m_isDeleted = true;

		virtual void reset() = 0;
	public:
		void accept(ComponentVisitor& visitor);
	};
}