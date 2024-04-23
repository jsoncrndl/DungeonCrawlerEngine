#pragma once

#include <EASTL/allocator.h>


namespace Engine::Game::ECS
{
	template <typename T>
	class ComponentFactory
	{
		using AllocatorType = eastl::allocator;


		ComponentFactory(AllocatorType allocator);
		// A bunch of factories for each component?

		static T create();
		
		
		static T destroy();


	};
	
	
	template<typename T>
	inline T ComponentFactory<T>::create()
	{
		return T();
	}


	template<typename T>
	inline T ComponentFactory<T>::destroy()
	{
		return T();
	}
}