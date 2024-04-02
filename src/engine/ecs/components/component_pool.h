#pragma once

#include <cstdint>
#include <memory>

#include "find_deleted_component_visitor.h"
#include "component.h"

namespace Engine::ECS
{
	class ComponentPoolBase
	{
	};

	template<typename T>
	class ComponentPool : ComponentPoolBase
	{
		T* m_components;
		uint16_t m_size;

		ComponentPool(uint16_t size);
	public:
		static std::shared_ptr<ComponentPool<T>> create(uint16_t size);
		~ComponentPool();

		T* getComponent();
	};

	template <typename T>
	T* ComponentPool<T>::getComponent()
	{
		FindDeletedComponentVisitor visitor;

		for (int32_t i = 0; i < m_size; ++i)
		{
			Component* component = m_components + i;

			component->accept(visitor);
			if (visitor.getResult() != nullptr)
			{
				return dynamic_cast<T*>(visitor.getResult());
			}
		}

		return nullptr;
	}

	template <typename T>
	std::shared_ptr<ComponentPool<T>> ComponentPool<T>::create(uint16_t size)
	{
		return std::shared_ptr<ComponentPool<T>>(new ComponentPool(size));
	}

	template<typename T>
	ComponentPool<T>::ComponentPool(uint16_t size) : m_size(size)
	{
		m_components = new T[size];
		for (int i = 0; i < size; i++)
		{
			m_components[i].reset();
		}
	}

	template<typename T>
	ComponentPool<T>::~ComponentPool()
	{
		delete[] m_components;
	}
}