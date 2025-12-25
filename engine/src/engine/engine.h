#pragma once

#include <memory>
#include <EASTL/string.h>
#include <EASTL/functional.h>

#include "game_like.h"
#include "memory/permanent_allocator.h"
#include "memory/factory.h"

#if !DCE_DEDICATED_SERVER

#include "graphics/game_window.h"
#include "graphics/graphics.h"
#include "graphics/render_pipeline.h"
#include "sdl_event_dispatcher.h"
#include "resource/registry.h"
#include "resource/asset_manager.h"
#include "input/input_receiver.h"

#endif

namespace Engine
{
	namespace Game
	{
		class Game;
	}

	class RuntimeEngine
	{
	public:
		static RuntimeEngine Engine;

	private:
		using EngineAllocator = Memory::PermanentAllocator;
		EngineAllocator m_allocator{ Memory::Block(), "Engine Allocator" };

		Memory::Factory<EngineAllocator> m_factory{ &m_allocator };

		bool m_shouldQuit = false;
		bool m_isStarted = false;
		
		GameLike* m_activeGame;
		GameLike* m_nextGame;

		void mainLoop();
		void initGraphics();
		void initialize();
		RuntimeEngine(Memory::Block block);

	public:
		void start();
		EngineAllocator* getAllocator();
		
		void loadGame(GameLike* game);
		void closeGame();
		void quit();

		static void cleanUp();

#if !DCE_DEDICATED_SERVER
		
	private:
		Input::Input* m_input;
		Graphics::GameWindow* m_window;
		Graphics::Graphics* m_graphics;
		EventDispatcher* m_eventDispatcher;
		Resources::AssetManager* m_assetManager;

	public:
		Graphics::GameWindow* getWindow();
		Resources::AssetManager* getAssetManager();
		
		Graphics::Graphics* getGraphics();

#endif

	};

}