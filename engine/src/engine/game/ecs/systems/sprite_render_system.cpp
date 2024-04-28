#include "sprite_render_system.h"
#include "../entities/entity.h"


namespace Engine::Game::ECS
{
    void SpriteRenderSystem::render(Graphics::Graphics* graphics)
    {
        // Sort sprites by materials and organize into layers
        // Draw all the sprites back to front

        // Make an array of sprite renderer pointers on game stack allocator and sort it

        for (const SpriteRenderer& spriteRenderer : *m_sprites)
        {
            graphics->drawSprite(spriteRenderer.getSprite(), spriteRenderer.getTransform()->getWorldPosition(), spriteRenderer.getTransform()->getSize(), spriteRenderer.getTransform()->getWorldRotation(), spriteRenderer.getMaterial());
        }
    }

    void SpriteRenderSystem::setSprites(SpriteList* sprites)
    {
        m_sprites = sprites;
    }
}