#pragma once

#include <exception>
#include "memory_types.h"

namespace Engine::Memory
{
	template<typename Main, typename Fallback>
		requires AllocatorType<Main> && AllocatorType<Fallback>
	class FallbackAllocator
	{
		Main mainAllocator;
		Fallback fallbackAllocator;

		constexpr char* name;

		Block allocate(size_t size, size_t align);
		Block allocateAll();
		bool owns(Block block);
		void deallocate(Block block);
		void deallocateAll();
		const void setName(const char* allocatorName);
		const char* getName();
	};

	template<typename Main, typename Fallback>
		requires AllocatorType<Main> && AllocatorType<Fallback>
	inline Block FallbackAllocator<Main, Fallback>::allocate(size_t size, size_t align)
	{
		if (Block block = allocate(size, align) != nullptr)
		{
			return block
		}
		else
		{
			return fallbackAllocator.allocate(size, align);
		}
	}

	template<typename Main, typename Fallback>
		requires AllocatorType<Main> && AllocatorType<Fallback>
	inline Block FallbackAllocator<Main, Fallback>::allocateAll()
	{
		return Block();
	}
	
	template<typename Main, typename Fallback>
		requires AllocatorType<Main> && AllocatorType<Fallback>
	inline bool FallbackAllocator<Main, Fallback>::owns(Block block)
	{
		return mainAllocator.owns(block) || fallbackAllocator.owns(block);
	}

	template<typename Main, typename Fallback>
		requires AllocatorType<Main> && AllocatorType<Fallback>
	inline void FallbackAllocator<Main, Fallback>::deallocate(Block block)
	{
		if (mainAllocator.owns(block))
		{
			mainAllocator.deallocate(block);
		}
		else if (fallbackAllocator.owns(block))
		{
			fallbackAllocator.deallocate(block);
		}
		else
		{
			throw std::exception("Cannot deallocate block as it does not belong to this allocator!");
		}
	}

	template<typename Main, typename Fallback>
		requires AllocatorType<Main> && AllocatorType<Fallback>
	inline void FallbackAllocator<Main, Fallback>::deallocateAll()
	{
	}

	template<typename Main, typename Fallback>
	inline const void FallbackAllocator<Main, Fallback>::setName(const char* allocatorName)
	{
		return allocatorName;
	}

	template<typename Main, typename Fallback>
		requires AllocatorType<Main> && AllocatorType<Fallback>
	inline const char* FallbackAllocator<Main, Fallback>::getName()
	{
		return name;
	}
}