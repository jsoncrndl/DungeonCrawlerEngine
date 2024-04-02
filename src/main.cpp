#include <iostream>
#include "SDL.h"
#include "engine/engine.h"
#include "engine/math/math_types.h"
#include "engine/ecs/components/component_pool.h"
#include "engine/ecs/components/transform.h"

int SDL_main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return -1;
    }

    Engine::RuntimeEngine::create()->start();
   
    //std::shared_ptr<Engine::ECS::ComponentPool<Engine::ECS::Transform>> pool = Engine::ECS::ComponentPool<Engine::ECS::Transform>::create(100);

    //int i = 0;
    //while (pool->getComponent() != nullptr)
    //{
    //    std::cout << i++ << "\n";
    //}

    // Quit SDL
    SDL_Quit();

    return 0;
}

