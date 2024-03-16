#include <iostream>
#include "SDL.h"
#include "engine/game.h"
#include "engine/graphics/texture.h"
#include "engine/resource/texture_importer.h"
#include "engine/resource/registry.h"

int SDL_main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return -1;
    }

    using namespace Engine;

    Engine::Game game = Engine::Game();

    // Quit SDL
    SDL_Quit();

    return 0;
}