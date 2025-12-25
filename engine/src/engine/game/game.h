#pragma once
#include <array>
#include "states/game_state.h"
#include "states/gs_loading.h"
#include "states/gs_level.h"
#include "engine/game/network/network_manager.h"
#include "game_settings.h"
#include "engine/memory/factory.h"
#include "engine/game_like.h"
 
#if !DCE_DEDICATED_SERVER

#include "engine/graphics/render_pipeline.h"

#endif


//#include "level/level.h"

namespace Engine::Game
{
	class Engine::RuntimeEngine;
	class Engine::GameLike;

	class Game : public GameLike
	{
	public:
		static Game* ActiveGame;
		using GameAllocator = Memory::PermanentAllocator;
	private:
		// States
		GameAllocator m_allocator;
		Memory::Factory<GameAllocator> m_factory;
		Network::NetworkManager* m_networkManager;

		LoadingGameState loadingState;
		LevelGameState levelState;

		GameStateType m_nextState;

		void initializeStates();

	public:

		Game(GameAllocator allocator, Network::ConnectionType connectionType);

		void initialize() override;
		void update(float deltaSeconds) override;
		void quit() override;

		GameAllocator* getAllocator();
		Network::NetworkManager* getNetworkManager();
		// Assets and resources

#if !DCE_DEDICATED_SERVER

	private:
		Graphics::RenderPipeline* m_renderPipeline;
	public:
		void receiveInput(const Input::InputEvent& event) override;
		void render() override;
#endif

	};
}