#pragma once

#include "graphics/game_window.h"
#include "graphics/graphics.h"
#include "graphics/render_pipeline.h"
#include "memory"
#include "sdl_event_dispatcher.h"

namespace Engine
{
	class Game
	{
	private:
		std::shared_ptr<EventDispatcher> m_eventDispatcher;
		std::shared_ptr<Graphics::GameWindow> m_window;
		std::shared_ptr<Graphics::Graphics> m_graphics;
		std::shared_ptr<Graphics::RenderPipeline> m_renderPipeline;

		bool m_shouldQuit = false;

		void mainLoop();
		void initGraphics();

	public:

		Game();

		void initialize();

		void loadContent();
		void handleInput();
		void update(float deltaTime);
		void render();
		void quit();

		void setRenderPipeline(std::shared_ptr<Graphics::RenderPipeline> pipeline);
	};
}