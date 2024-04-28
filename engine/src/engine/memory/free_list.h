#pragma once

#include "memory_types.h"

namespace Engine::Memory
{
    class FreeList
    {
        class FreeListNode
        {
        public:
            FreeListNode* nextElement;
            size_t blockSize;
        };

        FreeListNode* root;
        
    public:
        FreeList();
        Block popFirst();
        Block firstFit(const size_t& size, const size_t& align);
        void insert(Block block);
        bool isEmpty() const;
    };
}