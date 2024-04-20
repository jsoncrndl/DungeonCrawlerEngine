#pragma once
#include "memory_types.h"


namespace Engine::Memory
{
	class NullAllocator
	{
		Block allocate(size_t size, size_t align);
		Block allocateAll();
		bool owns(Block block);
		void deallocate(Block block);
		void deallocateAll();
		const char* getName();
	};
}