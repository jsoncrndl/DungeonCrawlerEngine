#pragma once

namespace Engine::Memory
{
    struct Block
    {
        void* ptr;
        size_t size;
        Block();
        Block(void* ptr, size_t size);

        bool operator ==(void* other);
    };

    inline Block::Block() : Block(nullptr, 0)
    {
    }

    inline Block::Block(void* ptr, size_t size) : ptr(ptr), size(size)
    {
    }

    inline bool Block::operator==(void* other)
    {
        return ptr == other;
    }


    template <typename T>
    concept AllocatorType = requires(T allocator, size_t size, Block block, bool owns, char* name) {
        block = allocator.allocate(size, size);
        allocator.deallocate(block);
        owns = allocator.owns(block);
        name = allocator.getName();
    };
}