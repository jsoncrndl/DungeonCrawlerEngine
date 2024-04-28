#pragma once

#include <exception>
#include <memory>
#include "memory_types.h"
#include "free_list.h"
#include "memory_utils.h"


namespace Engine::Memory
{
	/// <summary>
	/// A fixed-size memory pool allocator.
	/// </summary>
	/// <typeparam name="ElementSize">Size of block to be allocated from the pool</typeparam>
	/// <typeparam name="ElementAlign">Alignment of block to be allocated from the pool</typeparam>
	template <size_t ElementSize, size_t ElementAlign>
	class PoolAllocator
	{
		const char* m_name;
		Block m_allocatedBlock;
		FreeList m_freeList;
		size_t m_allocationCount;
		size_t m_maxSize;

	public:
		PoolAllocator(Block allocationBlock, const char* name);

		Block allocate(size_t size, size_t align);
		bool owns(Block block);
		void deallocate(Block block);
		const char* getName();
		const size_t maxSize();
	};

	template<size_t ElementSize, size_t ElementAlign>
	inline PoolAllocator<ElementSize, ElementAlign>::PoolAllocator(Block block, const char* name) : m_allocatedBlock(block), m_name(name), m_allocationCount(0)
	{
		
		size_t remainingSpace = block.size;

		void* m_dataStart = std::align(ElementAlign, ElementSize, block.ptr, remainingSpace);

		// Divide block into smaller blocks and add to free list

		for (uint8_t* start = static_cast<uint8_t*>(m_dataStart); remainingSpace >= ElementSize; start += ElementSize, remainingSpace -= ElementSize)
		{
			m_freeList.insert(Block(static_cast<void*>(start), ElementSize));
		}
	}

	template<size_t ElementSize, size_t ElementAlign>
	inline Block PoolAllocator<ElementSize, ElementAlign>::allocate(size_t size, size_t align)
	{
		if (size != ElementSize || align != ElementAlign)
		{
			throw std::exception("Requested allocation doesn't match pool size and alignment.");
		}

		// Keep track of how many allocations have been made
		++m_allocationCount;

		return m_freeList.popFirst();
	}

	template<size_t ElementSize, size_t ElementAlign>
	inline bool PoolAllocator<ElementSize, ElementAlign>::owns(Block block)
	{
		return MemoryUtils::isSubBlock(block, m_allocatedBlock);
	}

	template<size_t ElementSize, size_t ElementAlign>
	inline void PoolAllocator<ElementSize, ElementAlign>::deallocate(Block block)
	{
		if (!owns(Block))
		{
			throw std::exception("Cannot deallocate block as it does not belong to this allocator!");
		}

		--m_allocationCount;
		m_freeList.insert(block);
	}

	template<size_t ElementSize, size_t ElementAlign>
	inline const char* PoolAllocator<ElementSize, ElementAlign>::getName()
	{
		return m_name;
	}

	template<size_t ElementSize, size_t ElementAlign>
	inline const size_t PoolAllocator<ElementSize, ElementAlign>::maxSize()
	{
		return m_maxSize;
	}
}