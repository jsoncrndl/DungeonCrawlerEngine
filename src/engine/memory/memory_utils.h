#pragma once
#include "memory_types.h"
#include "cmath"

namespace Engine::Memory::MemoryUtils
{
	inline bool isSubBlock(Block subBlock, Block parent)
	{
		return subBlock.ptr >= parent.ptr && static_cast<uint8_t*>(subBlock.ptr) + subBlock.size < static_cast<uint8_t*>(parent.ptr) + subBlock.size;
	}
}