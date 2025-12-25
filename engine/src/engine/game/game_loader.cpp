#include "game_loader.h"

namespace Engine::Game
{
    Game* GameLoader::loadGame(eastl::string filePath, Network::ConnectionType connectionType)
    {
        // Games have their own memory separate from the engine, so this will need to allocate all the memory for a game.

        // Load zip file with miniz, then extract the game settings file
        
        //mz_zip_archive archive;

        //mz_zip_reader_init_file(&archive, "test_game.dce", 0);

        return nullptr;
    }
}