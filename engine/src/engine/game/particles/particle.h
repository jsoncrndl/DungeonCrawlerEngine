#pragma once

#include "engine/math_types.h"
#include "engine/color.h"

namespace Engine::Game
{
    struct Particle
    {
        Vector2 velocity;
        Vector2 acceleration;
        Color color;
        float lifetime;
    };
}