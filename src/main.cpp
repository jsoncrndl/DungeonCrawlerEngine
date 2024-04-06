#include <iostream>
#include "SDL.h"
#include "engine/engine.h"
#include "engine/math/math_types.h"
#include "engine/game/ecs/components/transform.h"

int SDL_main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return -1;
    }

    Engine::RuntimeEngine::create()->start();
   
    // Quit SDL
    SDL_Quit();

    return 0;
}