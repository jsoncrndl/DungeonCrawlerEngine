#pragma once

enum GameStateType
{
	LOADING = 0,
	LEVEL = 1
};

class GameState
{
	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};