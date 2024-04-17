#pragma once

namespace Engine::Game
{
    template <typename T>
    class PoolArray
    {
        T* m_location;
        uint16_t m_size;

    public:
        PoolArray();
        PoolArray(T* location, const uint16_t& size);

        T& operator[](const uint16_t& index);
    };

    template <typename T>
    PoolArray<T>::PoolArray(T* location, const uint16_t& size) : m_location(location), m_size(size)
    {
    }

    template <typename T>
    PoolArray<T>::PoolArray() : m_location(nullptr), m_size(0)
    {
    }

    template <typename T>
    T& PoolArray<T>::operator[](const uint16_t& index)
    {
        if (index >= m_size)
        {
            throw std::out_of_range();
        }

        return m_location + m_size;
    }
}