#include "game_builder.h"
#include "engine/memory/factory.h"
#include "engine/memory/byte_literals.h"

namespace Engine::Game
{
	GameBuilder* GameBuilder::settings(GameSettings settings)
	{
		return this;
	}

	GameBuilder* GameBuilder::maxLoadedLevels(uint8_t maxLevels)
	{
		m_maxLevels = maxLevels;
		return this;
	}

	GameBuilder* GameBuilder::connectionType(Network::ConnectionType connectionType)
	{
		m_connectionType = connectionType;
		return this;
	}

	Game* GameBuilder::build()
	{
		using namespace Engine::Memory;
		using namespace Engine::Memory::ByteLiterals;

		// Should calculate how much memory the game will need based on different settings
		Block block{ std::malloc(1_GiB), 1_GiB };
		Game::GameAllocator allocator{ block, "Game Allocator" };
		
		void* gamePtr = allocator.allocate(sizeof(Game), alignof(Game)).ptr;
		Game* game = new(gamePtr) Game(allocator, m_connectionType);

		return game;
	}
}