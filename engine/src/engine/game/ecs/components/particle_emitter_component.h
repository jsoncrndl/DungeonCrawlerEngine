#pragma once

#include "component.h"
#include "engine/game/particles/particle_emitter.h"

namespace Engine::Game::ECS
{
    /// <summary>
    /// Particle emitters don't 
    /// </summary>
    class ParticleEmitterComponent : public Component
    {
        float currentTime;
        ParticleEmitter* emitter;
    };
}