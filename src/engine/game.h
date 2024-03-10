#pragma once

#include "graphics/game_window.h"
#include "memory"

class Game 
{
private:
	std::shared_ptr<GameWindow> window;
	bool shouldQuit = false;
	
	void mainLoop();

public:

	Game();

	void initialize();
	void loadContent();
	void handleInput();
	void update(float deltaTime);
	void render();
};