#pragma once
#include "memory_types.h"
#include "null_allocator.h"
#include <exception>

namespace Engine::Memory
{
	Block NullAllocator::allocate(size_t size, size_t align)
	{
		return Block();
	}
	Block NullAllocator::allocateAll()
	{
		return Block();
	}
	bool NullAllocator::owns(Block block)
	{
		return block.ptr == nullptr;
	}
	void NullAllocator::deallocate(Block block)
	{
		if (block.ptr != nullptr)
		{
			throw std::exception("Null allocator tried to deallocate non-null memory!");
		}
	}

	void NullAllocator::deallocateAll()
	{
	}

	const char* NullAllocator::getName()
	{
		return "Null allocator";
	}
}