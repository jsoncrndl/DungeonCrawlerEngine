#include "permanent_allocator.h"
#include "permanent_allocator.h"
#include <iostream>

namespace Engine::Memory
{
    PermanentAllocator::PermanentAllocator(Block block, const char* name) : m_freeMemory(block.ptr), m_remainingSpace(block.size), m_allocatedBlock(block), m_name(name)
    {
    }

    Block PermanentAllocator::allocate(size_t size, size_t align)
    {
        void* allocateStart = std::align(align, size, m_freeMemory, m_remainingSpace);

        m_remainingSpace -= size;
        m_freeMemory = static_cast<uint8_t*>(allocateStart) + size;

        if (allocateStart == nullptr)
        {
            throw std::exception("Out of memory!");
        }

        return allocateStart == nullptr ? Block() : Block(allocateStart, size);
    }

    void* PermanentAllocator::allocate(size_t size, int flags)
    {
        return allocate(size, size_t(8)).ptr;
    }

    void* PermanentAllocator::allocate(size_t size, size_t alignment, size_t offset, int flags)
    {
        return allocate(size, alignment).ptr;
    }

    void PermanentAllocator::deallocate(void* p, size_t n)
    {
    }

    void PermanentAllocator::deallocateAll()
    {
        m_freeMemory = m_allocatedBlock.ptr;
        m_remainingSpace = m_allocatedBlock.size;
    }

    const char* PermanentAllocator::getName()
    {
        return m_name;
    }

    const size_t PermanentAllocator::remainingSpace()
    {
        return m_remainingSpace;
    }

    void Engine::Memory::PermanentAllocator::setBlock(Block block)
    {
        if (m_allocatedBlock != nullptr)
        {
            throw std::exception("Cannot set block! Allocator has already been allocated!");
        }

        m_allocatedBlock = block;
    }
    Block PermanentAllocator::getBlock()
    {
        return m_allocatedBlock;
    }
}