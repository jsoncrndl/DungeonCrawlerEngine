#include <SDL.h>
#include <engine/engine.h>
#include <engine/game/game_builder.h>
#include <engine/color.h>
#include <engine/game/game.h>
#include "menu/menu.h"

int SDL_main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return -1;
    }

    /*DCEPlayer::Menu* menu = new DCEPlayer::Menu();*/

    Engine::Game::Game* game = Engine::Game::GameBuilder().connectionType(Engine::Game::Network::ConnectionType::HOST)->build();

    // Load
    Engine::RuntimeEngine::Engine.loadGame(game);
    Engine::RuntimeEngine::Engine.start();
    Engine::RuntimeEngine::cleanUp();

    //delete menu;

    // Quit SDL
    SDL_Quit();

    return 0;
}