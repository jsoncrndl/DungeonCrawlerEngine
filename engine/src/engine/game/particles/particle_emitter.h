#pragma once

#include "engine/math_types.h"
#include "engine/graphics/material.h"

namespace Engine::Game
{
	class ParticleEmitter
	{
		enum EmissionSourceType
		{
			RECTANGLE,
			POINT,
			RECT
		};
		struct RectangleEmissionSource
		{
			Rect emissionArea;
		};
		struct CircleEmissionSource
		{
			Vector2 center;
			float radius;
		};
		struct PointEmissionSource
		{
			Vector2 center;
		};
		union EmissionSource
		{
			RectangleEmissionSource rectangleSource;
			CircleEmissionSource circleSource;
			PointEmissionSource pointSource;
		};


	private:

		// Emission
		EmissionSourceType m_emissionType;
		EmissionSource m_source;
		float emissionRate;



		Graphics::Material m_material;

		/*
			Things a particle emitter has:

			A bunch of statically allocated modifiers (one of each only) with values that can be customized
			
			Emission modifiers:
				Emission shape
				Emission rate

			Rendering properties
				Material
				Flipbook size (add later)
		*/
	};
}