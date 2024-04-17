#include <cstdlib>
#include <exception>
#include "memory_pool.h"


namespace Engine::Game
{
	void MemoryPool::reserve(uint16_t size)
	{
		if (m_parent == nullptr)
		{
			m_memory = std::malloc(size);
		}
		else
		{
			m_memory = m_parent->allocateRaw(size);
		}
		if (m_memory == nullptr)
		{
			throw std::bad_alloc();
		}
	}

	MemoryPool::MemoryPool(MemoryPool* parent) : m_parent(parent), m_size(0), m_memory(nullptr), m_freeMemory(nullptr)
	{
		parent->children.push_back(this);
	}

	MemoryPool::MemoryPool() : m_parent(nullptr), m_size(0), m_memory(nullptr), m_freeMemory(nullptr)
	{
	}

	/// <summary>
	/// Clean up memory pool when done. This should only be called on the parent pool
	/// </summary>
	void MemoryPool::free()
	{
		if (m_parent == nullptr)
		{
			std::free(m_memory);
			m_memory = nullptr;
			m_freeMemory = nullptr;
		}
		else
		{
			for (MemoryPool* pool : children)
			{
				pool->free();
			}
		}
	}

	void* MemoryPool::allocateRaw(uint16_t bytes)
	{
		void* data;
		if (static_cast<uint8_t*>(m_freeMemory) + bytes >= static_cast<uint8_t*>(m_memory) + m_size)
		{
			data = nullptr;
		}
		else
		{
			data = m_freeMemory;
			m_freeMemory = static_cast<void*>(static_cast<uint8_t*>(m_freeMemory) + bytes);
		}

		return data;
	}
}