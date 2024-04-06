#pragma once
#include <cstdint>
#include <iostream>

namespace Engine::Game
{
	/// <summary>
	/// Memory for ECS pools. Does not support freeing individual pools yet since they are expected to be allocated once then used throughout a game's lifetime
	/// </summary>
	class MemoryPool
	{
	private:
		MemoryPool* m_parent = nullptr;
		void* m_memory;
		void* m_freeMemory;
		uint16_t m_size;

	public:
		MemoryPool(MemoryPool* parent);

		void reserve(uint16_t bytes);
		
		void free();

		void* allocateRaw(uint16_t size);

		template <typename T>
		T* allocate(uint16_t size);
	};

	template<typename T>
	T* MemoryPool::allocate(uint16_t elements)
	{
		// Calculate any padding needed before placing the data

		auto padding = alignof(T) - reinterpret_cast<uintptr_t>(m_freeMemory) % alignof(T);
		void* allocateStart = reinterpret_cast<void*>(static_cast<uint8_t*>(m_freeMemory) + padding);

		T* data;
		if (static_cast<T*>(allocateStart) + elements >= static_cast<T*>(m_memory) + m_size)
		{
			data = nullptr;
		}
		else
		{
			data = static_cast<T*>(allocateStart);
			m_freeMemory = static_cast<T*>(allocateStart) + elements;
		}

		return data;
	}
}