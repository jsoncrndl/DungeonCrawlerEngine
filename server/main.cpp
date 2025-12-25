#include <engine/engine.h>
#include <iostream>
// Start a dedicated server

int main(int argc, char* argv[])
{
    using namespace Engine::Game;

    // Load game settings based on command line arguments
    
    Engine::RuntimeEngine::Engine.start();
    Engine::RuntimeEngine::cleanUp();

    return 0;
}