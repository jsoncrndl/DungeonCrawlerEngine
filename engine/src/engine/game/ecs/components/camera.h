#pragma once

#include "component.h"
#include "engine/math_types.h"

namespace Engine::Game::ECS
{
	class Camera : public Component
	{
		float pixelsPerUnit;
		
	public:
		Matrix3x3 getProjectionMatrix();
	};
}