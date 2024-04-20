#include "stack_allocator.h"
#include "memory_utils.h"

namespace Engine::Memory
{
    StackAllocator::StackAllocator(Block block, const char* name) : m_freeMemory(block.ptr), m_remainingSpace(block.size), m_allocatedBlock(block), m_name(name)
    {
    }

    Block StackAllocator::allocate(size_t size, size_t align)
    {
        void* allocateStart = std::align(align, size, m_freeMemory, m_remainingSpace);

        m_remainingSpace -= size;
        m_freeMemory = static_cast<uint8_t*>(allocateStart) + size;

        return allocateStart == nullptr ? Block() : Block(allocateStart, size);
    }

    bool StackAllocator::owns(Block block)
    {
        return MemoryUtils::isSubBlock(block, m_allocatedBlock);
    }

    void StackAllocator::deallocate(Block block)
    {
        if (!owns(block))
        {
            throw std::exception("Cannot deallocate block as it does not belong to this allocator!");
        }

        // If this is the last element, don't add it to the free list
        if (static_cast<uint8_t*>(block.ptr) + block.size == static_cast<uint8_t*>(m_freeMemory))
        {
            m_freeMemory = block.ptr;

            // Possible loss of memory from alignment issues
            m_remainingSpace += block.size;
        }
        else
        {
            //m_freeList.insert(block);
        }
    }

    const char* StackAllocator::getName()
    {
        return m_name;
    }

    const size_t StackAllocator::remainingSpace()
    {
        return m_remainingSpace;
    }
}