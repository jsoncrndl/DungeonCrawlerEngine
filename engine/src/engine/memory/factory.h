#pragma once

namespace Engine::Memory
{
	template <typename Allocator>
	class Factory
	{
	private:
		Allocator* m_allocator;

	public:
		Factory(Allocator* allocator);

		template <typename T, typename... Args>
		T* create(Args... args);

		template <typename T>
		void free(T* ptr);
	};

	template<typename Allocator>
	template<typename T, typename... Args>
	inline T* Factory<Allocator>::create(Args... args)
	{
		return new(m_allocator->allocate(sizeof(T), alignof(T)).ptr) T(args...);
	}

	template<typename Allocator>
	template<typename T>
	inline void Factory<Allocator>::free(T* ptr)
	{
		ptr->~T();
		m_allocator->free(ptr);
	}

	template<typename Allocator>
	inline Factory<Allocator>::Factory(Allocator* allocator) : m_allocator(allocator)
	{
	}
}