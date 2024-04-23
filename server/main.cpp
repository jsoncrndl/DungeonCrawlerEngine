#include <engine/engine.h>
#include <iostream>

// Start a dedicated server

int main(int argc, char* argv[])
{
    Engine::RuntimeEngine::Engine.start();
    Engine::RuntimeEngine::cleanUp();

    return 0;
}