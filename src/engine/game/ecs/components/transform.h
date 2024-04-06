#pragma once

#include "component.h"
#include "../../../math/math_types.h"

namespace Engine::Game::ECS
{
	class Transform : public Component
	{
	private:
		Transform* m_parent;
		Vector2 m_localPosition;
		Vector2 m_localScale;
		float m_localRotation;

	public:
		Vector2 getWorldPosition() const;
		float getWorldRotation() const;

		Vector2 getLocalPosition() const;
		float getLocalRotation() const;
		
		void setWorldPosition(const Vector2& position);
		void setWorldRotation(const float& rotation);

		void setLocalPosition(const Vector2& position);
		void setLocalRotation(const float& rotation);

		Transform* getParent() const;
		void setParent(Transform* parent);

		Vector2 getLocalScale() const;
		void setLocalScale(const Vector2& scale);

		void reset() override;
	};
}