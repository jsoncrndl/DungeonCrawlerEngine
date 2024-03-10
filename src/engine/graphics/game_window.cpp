#include "game_window.h"

std::shared_ptr<GameWindow> GameWindow::create(int bufferWidth, int bufferHeight)
{
	return std::shared_ptr<GameWindow>(new GameWindow(bufferWidth, bufferHeight));
}

void GameWindow::setBufferSize(int width, int height)
{
}

void GameWindow::resize(int width, int height)
{
	SDL_SetWindowSize(window, width, height);
}

void GameWindow::setPosition(int x, int y)
{
	SDL_SetWindowPosition(window, x, y);
}

void GameWindow::setFullscreen(bool fullscreen)
{
	SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void GameWindow::close()
{
}

void GameWindow::handleEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) > 0)
	{

	}
}

GameWindow::GameWindow(int bufferWidth, int bufferHeight) : 
	bufferWidth(bufferWidth),
	bufferHeight(bufferHeight)
{
	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window == nullptr) {
		SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
	}
}

GameWindow::~GameWindow()
{
	SDL_DestroyWindow(window);
}