#pragma once

#include <cstdint>
#include <memory>
#include "free_resource_visitor.h"
#include "reset_object_visitor.h"
#include "rttr/type.h"

namespace Engine::Game
{

	class ObjectPoolBase
	{
	protected:
		void* m_objects;
		uint16_t m_size;
		
		ObjectPoolBase(void* location, uint16_t size);
	};

	template<typename T>
	requires std::derived_from<T, PooledObject>
	class ObjectPool : public ObjectPoolBase
	{

	public:
		ObjectPool(T* location, uint16_t size);

		T* getObject();
	};

	template <typename T>
	requires std::derived_from<T, PooledObject>
	T* ObjectPool<T>::getObject()
	{
		FreeResourceVisitor visitor;
		for (int32_t i = 0; i < m_size; ++i)
		{
			PooledObject* object = static_cast<T>(m_objects) + i;

			object->accept(&visitor);
			if (visitor.getResult() != nullptr)
			{
				return dynamic_cast<T*>(visitor.getResult());
			}
		}

		return nullptr;
	}

	template<typename T>
	requires std::derived_from<T, PooledObject>
	ObjectPool<T>::ObjectPool(T* location, uint16_t size) : ObjectPoolBase(location, size)
	{
		ResetObjectVisitor reset;
		for (int i = 0; i < size; i++)
		{
			location[i].accept(&reset);
		}
	}
}