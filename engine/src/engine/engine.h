#pragma once

#include <memory>
#include <EASTL/string.h>

#include "memory/permanent_allocator.h"

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
#if !DCE_DEDICATED_SERVER
		: public Input::InputReceiver
#endif
	{
	public:
		static RuntimeEngine Engine;

	private:
		using EngineAllocator = Memory::PermanentAllocator;
		EngineAllocator m_allocator { Memory::Block(), "Engine Allocator" };

		class Factory
		{
		public:
			template <typename T>
			static T* create();

			template <typename T, typename Arg1>
			static T* create(Arg1 arg1);

			template <typename T, typename Arg1, typename Arg2>
			static T* create(Arg1 arg1, Arg2 arg2);
		};

		Game::Game* m_game;

		bool m_shouldQuit = false;
		bool m_isStarted = false;

		void mainLoop();
		void initGraphics();
		void initialize();
		void handleInput();
		void update(float deltaTime);
		void render();
		RuntimeEngine(Memory::Block block);

	public:
		void start();
		EngineAllocator* getAllocator();
		
		void loadGame(eastl::string path);
		void closeGame();

		void quit();

		static void cleanUp();

#if !DCE_DEDICATED_SERVER
		
	private:
		Input::Input* m_input;
		Graphics::GameWindow* m_window;
		Graphics::Graphics* m_graphics;
		Graphics::RenderPipeline* m_defaultRenderPipeline;
		EventDispatcher* m_eventDispatcher;
		Graphics::RenderPipeline* m_activeRenderPipeline;
		Resources::AssetManager* m_assetManager;

	public:
		Graphics::GameWindow* getWindow();
		Resources::AssetManager* getAssetManager();
		void setRenderPipeline(Graphics::RenderPipeline* pipeline);
		Graphics::Graphics* getGraphics();

		void receiveInput(const Input::InputEvent& event) override;

#endif

	};

	template<typename T>
	inline T* RuntimeEngine::Factory::create()
	{
		return new(RuntimeEngine::Engine.m_allocator.allocate(sizeof(T), alignof(T)).ptr) T();
	}
	template<typename T, typename Arg1>
	inline T* RuntimeEngine::Factory::create(Arg1 arg1)
	{
		Memory::Block block = RuntimeEngine::Engine.m_allocator.allocate(sizeof(T), alignof(T));
		return new(block.ptr) T(arg1);
	}
	template<typename T, typename Arg1, typename Arg2>
	inline T* RuntimeEngine::Factory::create(Arg1 arg1, Arg2 arg2)
	{
		return new(RuntimeEngine::Engine.m_allocator.allocate(sizeof(T), alignof(T)).ptr) T(arg1, arg2);
	}
}