#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include <EASTL/string.h>

#include "engine/memory/memory_types.h"
#include "engine/memory/permanent_allocator.h"


#if !DCE_DEDICATED_SERVER

#include "engine/graphics/graphics.h"
#include "../ecs/systems/sprite_render_system.h"
#include "../ecs/systems/particle_system.h"
#include "../ecs/systems/camera_system.h"

#endif

namespace Engine::Game
{
	class Game;
	class Level
	{
		/*template <typename T>
		using ComponentPool = Engine::Memory::PoolAllocator<sizeof(T), alignof(T)>;*/

		using LevelAllocator = Memory::PermanentAllocator;
		friend class LevelDeserializer;

	private:
	
		LevelAllocator m_allocator;
		Game* m_game;

		void allocateMemory();
		 
	public:
		Level(Game* game, const char* name, Memory::Block allocator);

		void postLoad();
		void update(float deltaSeconds);

		Game* getGame();
		// Systems
		// Entities
		// Components
		




#if !DCE_DEDICATED_SERVER
	private:
		ECS::SpriteRenderSystem* m_spriteRenderSystem;
		ECS::ParticleSystem* m_particleSystem;
		ECS::CameraSystem* m_cameraSystem;

	public:
		ECS::SpriteRenderSystem* getSpriteRenderSystem();
		ECS::ParticleSystem* getParticleSystem();
		ECS::CameraSystem* getCameraSystem();

		void render(Graphics::Graphics* graphics);

#endif
	};
}