#pragma once

#include "component.h"
#include "engine/math_types.h"
#include <memory>

#if !DCE_DEDICATED_SERVER

#include "engine/graphics/render_texture.h"

#endif

namespace Engine::Game::ECS
{
	class Camera : public Component
	{
		float m_frustumX;
		float m_frustumY;

#if !DCE_DEDICATED_SERVER
		std::shared_ptr<Graphics::RenderTexture> m_renderTarget;
#endif

	public:
		Matrix3x3 getProjectionMatrix();

		void setFrustum(Vector2 size);
		void setFrustum(float sizeX, float sizeY);
	};
}