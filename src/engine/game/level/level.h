#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include "../memory/object_pool.h"
#include "../memory/memory_pool.h"
#include "../memory/pooled_object.h"
#include "../ecs/components/transform.h"
#include "../ecs/entities/entity.h"
#include "../../graphics/graphics.h"

namespace Engine::Game
{
	class Game;
	class Level : public PooledObject
	{
		//friend class LevelSerializer;
		friend class LevelDeserializer;
		
		std::unordered_map<rttr::type, ObjectPoolBase*> m_componentPools;
		ObjectPool<ECS::Entity>* m_entityPool;
		MemoryPool m_memory;

		static const uint16_t maxEntities = 500;
		Game* m_game;

		void allocateMemory();

		template <typename T>
		requires std::derived_from<T, ECS::Component>
		void allocateComponent(uint16_t maxAmount);
		void allocateEntities(uint16_t maxAmount);
		ObjectPoolBase* getComponentPool(std::string type);

	public:
		Level(Game* game, MemoryPool memory);

		void postLoad();
		void update(float deltaSeconds);
		void render(std::shared_ptr<Graphics::Graphics> graphics);

		template <typename T>
		requires std::derived_from<T, ECS::Component>
		ObjectPool<T>* getComponentPool();
		
		ObjectPool<ECS::Entity>* getEntityPool();

		Game* getGame();

		virtual void reset();
		// Systems
		// Entities
		// Components

		
	};
	
	template<typename T>
	requires std::derived_from<T, ECS::Component>
	inline void Level::allocateComponent(uint16_t maxAmount)
	{
		rttr::type type = rttr::type::get<T>();

		if (m_componentPools.count(type) != 0)
		{
			std::cerr << "Already allocated an array for this component type";
			return;
		}

		// Allocate the memory for the pool
		T* poolData = m_memory.allocate<T>(maxAmount);
		ObjectPool<T>* pool = m_memory.allocate<ObjectPool<T>>(1);
		pool = new(pool) ObjectPool<T>(poolData, maxAmount);
		
		m_componentPools[type] = pool;
	}

	template<typename T>
	requires std::derived_from<T, ECS::Component>
	inline ObjectPool<T>* Level::getComponentPool()
	{
		rttr::type type = rttr::type::get<T>();

		if (m_componentPools.count(type) == 0)
		{
			return nullptr;
		}

		ObjectPoolBase* pool = m_componentPools[type];
	
		if (rttr::type::get(pool) != type)
		{
			return nullptr;
		}

		return dynamic_cast<ObjectPool<T>>(pool);
	}
}