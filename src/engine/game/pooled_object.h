#pragma once

namespace Engine::Game
{
    class FreeResourceVisitor;
    class ResetObjectVisitor;
    class PooledObjectVisitor;

    class PooledObject
    {
        friend class FreeResourceVisitor;
        friend class ResetObjectVisitor;

        bool m_isFree;

        virtual void reset() = 0;

    public:
        virtual void accept(PooledObjectVisitor* visitor);
    };
}