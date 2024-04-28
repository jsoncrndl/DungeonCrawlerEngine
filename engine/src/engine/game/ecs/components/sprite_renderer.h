#pragma once

#include <EASTL/string.h>
#include "component.h"

#if !DCE_DEDICATED_SERVER

#include "engine/graphics/sprite.h"
#include "engine/graphics/material.h"

#endif


namespace Engine::Game::ECS
{
    class SpriteRenderer : public Component
    {
    private:
        eastl::string m_defaultSprite;
        uint16_t m_sortOrder;

    public:
        uint16_t getSortOrder();
        eastl::string getDefaultSprite();

#if !DCE_DEDICATED_SERVER
    private:
        Graphics::Sprite m_sprite;
        std::shared_ptr<Graphics::Material> m_material;

    public:
        Graphics::Sprite getSprite() const;
        std::shared_ptr<Graphics::Material> getMaterial() const;
        void setSprite(const Graphics::Sprite& sprite);
#endif
    };
}