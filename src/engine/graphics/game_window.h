#pragma once

#include "SDL.h"
#include "memory"

class GameWindow
{
private:
	int bufferWidth;
	int bufferHeight;
	SDL_Window* window;
	GameWindow(int bufferWidth, int bufferHeight);

public:
	static std::shared_ptr<GameWindow> create(int bufferWidth, int bufferHeight);

	void setBufferSize(int width, int height);
	void resize(int width, int height);
	void setPosition(int x, int y);
	void setFullscreen(bool fullscreen);
	void close();
	void handleEvents();

	~GameWindow();
};