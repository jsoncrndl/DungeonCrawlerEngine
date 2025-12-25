#pragma once

#include <memory>
#include "memory_types.h"

namespace Engine::Memory
{
	class PermanentAllocator
	{
		Block m_allocatedBlock;

		void* m_freeMemory;
		size_t m_remainingSpace;
		const char* m_name;

	public:

		PermanentAllocator(Block block, const char* name = nullptr);

		Block allocate(size_t size, size_t align);
		void* allocate(size_t n, int flags = 0);
		void* allocate(size_t n, size_t alignment, size_t offset, int flags = 0);
		void deallocate(void* p, size_t n);
		void deallocateAll();
		const char* getName();
		const size_t remainingSpace();

		void setBlock(Block block);
		Block getBlock();
	};

}