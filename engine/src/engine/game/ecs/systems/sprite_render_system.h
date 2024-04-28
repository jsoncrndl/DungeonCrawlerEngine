#pragma once

#include <EASTL/vector.h>
#include "engine/graphics/graphics.h"
#include "engine/memory/pool_allocator.h"
#include "engine/game/ecs/components/sprite_renderer.h"

namespace Engine::Game::ECS
{
    class SpriteRenderSystem
    {
        using SpriteList = eastl::vector<SpriteRenderer>;
        SpriteList* m_sprites;

    public:
        void render(Graphics::Graphics* graphics);
        void setSprites(SpriteList* sprites);
    };
}