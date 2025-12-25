#pragma once

#include "EASTL/fixed_list.h"

namespace Engine::Game::ECS
{
	/// <summary>
	/// The internal implementation of this may change overtime. Calling get() will return a newly constructed object from the pool, and calling free will return it to the pool.
	/// </summary>
	template<typename Type, uint16_t MaxSize, typename NodeAllocator>
	class FixedPool
	{
		// Should it be a fixed list of entities or a list of entity ptrs allocated in a pool?
		eastl::fixed_list<NodeType, MaxSize, false> m_nodeList;

		Type* get();
		void free(Type* node);
	};

	template<typename Type, uint16_t MaxSize, typename NodeAllocator>
	inline Type* FixedPool<Type, MaxSize, NodeAllocator>::get()
	{
		m_nodeList.push_front(Type());
		return &m_nodeList.front();
	}

	template<typename Type, uint16_t MaxSize, typename NodeAllocator>
	inline void FixedPool<Type, MaxSize, NodeAllocator>::free(Type* node)
	{
		m_nodeList.remove(*node);
	}


}