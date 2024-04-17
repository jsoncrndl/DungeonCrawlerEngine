#include <iostream>
#include <SDL.h>
#include <string_view>
#include "engine/engine.h"
#include "engine/memory/byte_literals.h"

void parseArguments(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        std::string_view arg{ argv[i] };
        if (size_t index = arg.find("memory=") > 0)
        {
           std::string_view value = arg.substr(index + 7);
           // Split value at first non-number
           // Split value at first non-numb
        }
    }
}

int SDL_main(int argc, char* argv[])
{
    using namespace Engine::ByteLiterals;
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return -1;
    }
    
    Engine::RuntimeEngine::create(1_GiB)->start();

    // Quit SDL
    SDL_Quit();

    return 0;
}