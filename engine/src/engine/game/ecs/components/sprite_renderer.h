#pragma once

#include <EASTL/string.h>
#include "component.h"

#if !DCE_DEDICATED_SERVER

#include "../../../graphics/sprite.h"

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

    public:
        Graphics::Sprite getSprite();
        void setSprite(const Graphics::Sprite& sprite);
#endif
    };
}