#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include <EASTL/string.h>
#include "../../memory/memory_types.h"
#include "../../memory/permanent_allocator.h"


#if !DCE_DEDICATED_SERVER

#include "../../graphics/graphics.h"

#endif

namespace Engine::Game
{
	class Game;
	class Level
	{
		/*template <typename T>
		using ComponentPool = Engine::Memory::PoolAllocator<sizeof(T), alignof(T)>;*/

		using LevelAllocator = Memory::PermanentAllocator;

		//friend class LevelSerializer;
		friend class LevelDeserializer;

		LevelAllocator m_allocator;
		Game* m_game;

	private:
		void allocateMemory();

	public:
		Level(Game* game, const char* name, Memory::Block allocator);

		void postLoad();
		void update(float deltaSeconds);

		//template <typename T>
		//requires std::derived_from<T, ECS::Component>
		//ObjectPool<T>* getComponentPool();
		
		//ObjectPool<ECS::Entity>* getEntityPool();

		Game* getGame();
		// Systems
		// Entities
		// Components

		
#if !DCE_DEDICATED_SERVER

		void render(Graphics::Graphics* graphics);

#endif
	};
}