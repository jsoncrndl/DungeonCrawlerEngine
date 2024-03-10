#include "game.h"
#include <chrono>
#include <iostream>
// Game has a renderer, window, and a state
// It runs the main game loop
// The renderer is the render pipeline

void Game::mainLoop()
{
	float deltaTime = 0;

	while (!shouldQuit) {
		auto now = std::chrono::steady_clock::now();
		
		handleInput();
		update(deltaTime);
		render();

		auto endTime = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>((endTime - now)).count() / 1000000.0f;
	}
}

Game::Game()
{
	initialize();
	mainLoop();
}

void Game::initialize()
{
	window = GameWindow::create(240, 160);
}

void Game::loadContent()
{
}

void Game::handleInput()
{
	window->handleEvents();
}

void Game::update(float deltaTime)
{
}

void Game::render()
{
}
