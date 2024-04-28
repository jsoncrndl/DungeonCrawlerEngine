#pragma once

#include <exception>

#include "memory_types.h"
#include "free_list.h"

namespace Engine::Memory
{
	FreeList::FreeList() : root(nullptr)
	{
	}

	Block FreeList::popFirst()
	{
		if (root == nullptr)
		{
			return Block();
		}
		else
		{
			return Block(static_cast<void*>(root), root->blockSize);
		}
	}

	Block FreeList::firstFit(const size_t& size, const size_t& align)
	{
		// Iterate through free list
		for (FreeListNode* current = root; current != nullptr; current = current->nextElement)
		{
			// Check if node fits, then return as block.
			// return Block(static_cast<void*>(current), current->blockSize);
		}

		return Block();
	}
	void FreeList::insert(Block block)
	{
		if (block.size < sizeof(FreeListNode))
		{
			throw std::exception("Cannot add block to free list! It is too small!");
		}

		FreeListNode* newNode = (FreeListNode*)block.ptr;
		newNode->blockSize = block.size;
		newNode->nextElement = root;
		root = newNode;
	}

	bool Engine::Memory::FreeList::isEmpty() const
	{
		return root == nullptr;
	}
}