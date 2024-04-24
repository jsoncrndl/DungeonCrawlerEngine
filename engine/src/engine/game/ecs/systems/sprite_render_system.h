#pragma once

#include <EASTL/vector.h>
#include "../../../graphics/graphics.h"
#include "../../../memory/pool_allocator.h"
#include "../components/sprite_renderer.h"

namespace Engine::Game::ECS
{
    class SpriteRenderSystem
    {
        eastl::vector<SpriteRenderer, Memory::PoolAllocator>* sprites;

    public:
        void render(Graphics::Graphics* graphics);
    };
}