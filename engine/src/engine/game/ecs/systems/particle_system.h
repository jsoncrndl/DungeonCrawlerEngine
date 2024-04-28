#pragma once

#include "engine/graphics/graphics.h"
#include "eastl/fixed_list.h"
#include "engine/color.h"

namespace Engine::Game::ECS
{
    class ParticleSystem
    {

        // Each emitter has its own settings for how the particle should be changed each frame. Each component has a single emitter and timing data for it.
        // Particles emitters can also be used in particle effects, which is a timeline of emitters and settings for them.
        // Each frame update:
        //      Loop through each emitters particles and update it according to the emitters settings.
        // Loop through all particles and render
        // 
        // Each emitter has a max number of particles. When it is loaded, it allocates a particle pool with the particle system.
        // 

        //eastl::fixed_list<Particle> m_allParticles;
    
    public:
        void update(float deltaSeconds);
        void render(Graphics::Graphics* graphics);
    };
}