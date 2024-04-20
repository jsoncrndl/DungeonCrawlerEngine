#pragma once

#include <memory>

#include "graphics/game_window.h"
#include "graphics/graphics.h"
#include "graphics/render_pipeline.h"
#include "sdl_event_dispatcher.h"
#include "resource/registry.h"
#include "resource/asset_manager.h"
#include "game/game.h"

namespace Engine
{
	class RuntimeEngine
	{
		using EngineAllocator = Memory::StackAllocator;


		class Factory
		{
			static RuntimeEngine* create();
		};


	private:
		EngineAllocator allocator;


		const size_t MAX_MEMORY;

		EventDispatcher* m_eventDispatcher;
		Graphics::GameWindow* m_window;
		Graphics::Graphics* m_graphics;
		Graphics::RenderPipeline* m_renderPipeline;

		Resources::AssetManager* m_assetManager;

		Game::Game* m_game;

		static RuntimeEngine* instance;

		bool m_shouldQuit = false;
		bool m_isStarted = false;

		void mainLoop();
		void initGraphics();
		void allocateMemory();
		void initialize();
		void loadContent();
		void handleInput();
		void update(float deltaTime);
		void render();
		RuntimeEngine(size_t maxMemory);

	public:
		void start();
		static RuntimeEngine* create(uint64_t reservedMemory);
		static RuntimeEngine* getInstance();

		Graphics::GameWindow* getWindow();
		Resources::AssetManager* getAssetManager();
		
		void loadGame(std::string path);
		void closeGame();

		void quit();
		void setRenderPipeline(Graphics::RenderPipeline* pipeline);
	};
}