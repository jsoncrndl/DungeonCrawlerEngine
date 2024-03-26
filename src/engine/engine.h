#pragma once

#include <memory>

#include "graphics/game_window.h"
#include "graphics/graphics.h"
#include "graphics/render_pipeline.h"
#include "sdl_event_dispatcher.h"
#include "resource/registry.h"
#include "resource/asset_manager.h"

namespace Engine
{
	class RuntimeEngine
	{
	private:

		std::shared_ptr<EventDispatcher> m_eventDispatcher;
		std::shared_ptr<Graphics::GameWindow> m_window;
		std::shared_ptr<Graphics::Graphics> m_graphics;
		std::shared_ptr<Graphics::RenderPipeline> m_renderPipeline;

		std::shared_ptr<Resources::AssetManager> m_assetManager;

		static std::shared_ptr<RuntimeEngine> instance;

		bool m_shouldQuit = false;
		bool m_isStarted = false;

		void mainLoop();
		void initGraphics();

		void initialize();

		void loadContent();
		void handleInput();
		void update(float deltaTime);
		void render();
		RuntimeEngine();



	public:
		void start();
		static std::shared_ptr<RuntimeEngine> create();
		static std::shared_ptr<RuntimeEngine> getInstance();

		std::shared_ptr<Graphics::GameWindow> getWindow();
		std::shared_ptr<Resources::AssetManager> getAssetManager();
		void quit();
		void setRenderPipeline(std::shared_ptr<Graphics::RenderPipeline> pipeline);
	};
}