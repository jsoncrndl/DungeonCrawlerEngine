#pragma once

#include <engine/game_like.h>
#include <engine/input/input_event.h>

namespace DCEPlayer
{
    class Menu : public Engine::GameLike
    {
        void initialize();
		void receiveInput(const Engine::Input::InputEvent& input);
		void update(float deltaSeconds);
		void render();
		void quit();
    };
}