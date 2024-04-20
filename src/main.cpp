#include <iostream>
#include <SDL.h>
#include <string_view>
#include "engine/engine.h"
#include "engine/memory/byte_literals.h"
#include <memory>
#include "engine/memory/memory_types.h"
#include "engine/memory/pool_allocator.h"
#include "engine/memory/stack_allocator.h"

void parseArguments(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        std::string_view arg{ argv[i] };
        if (size_t index = arg.find("memory=") > 0)
        {
           std::string_view value = arg.substr(index + 7);
           // Split value at first non-number
        }
    }
}

int SDL_main(int argc, char* argv[])
{
    using namespace Engine::Memory::ByteLiterals;
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return -1;
    }
    
    //Engine::RuntimeEngine::create(1_GiB)->start();

    void* mem = std::malloc(100_MiB);
    
    
    Engine::Memory::StackAllocator stack { Engine::Memory::Block(mem, 30), "Stack Allocator"};

    
    Engine::Memory::Block result = stack.allocate(10, 8);
    Engine::Memory::Block result2 = stack.allocate(10, 8);

    /*Engine::Memory::Block block{ mem, 128 };

    Engine::Memory::PoolAllocator<64, 8> pool{ block, "Test Allocator" };

    for (int i = 0; i < 1000; i++)
    {
        Engine::Memory::Block result = pool.allocate(64, 8);
    }

    Engine::Memory::Block*/

    


    // Quit SDL
    SDL_Quit();

    return 0;
}