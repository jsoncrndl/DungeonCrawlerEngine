#pragma once

#include <memory>
#include "memory_types.h"
#include "free_list.h"

namespace Engine::Memory
{
	class StackAllocator
	{
		Block m_allocatedBlock;
		FreeList m_freeList;

		void* m_freeMemory;
		size_t m_remainingSpace;
		const char* m_name;

	public:

		StackAllocator(Block block, const char* name);

		Block allocate(size_t size, size_t align);
		bool owns(Block block);
		void deallocate(Block block);
		const char* getName();
		const size_t remainingSpace();
	};
}