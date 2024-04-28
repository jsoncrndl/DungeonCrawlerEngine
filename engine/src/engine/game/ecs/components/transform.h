#pragma once

#include "component.h"
#include "engine/math_types.h"

namespace Engine::Game::ECS
{
	class Transform : public Component
	{
	private:
		Transform* m_parent;
		Vector2 m_localPosition;
		Vector2 m_size;
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

		Vector2 getSize() const;
		void setSize(const Vector2& scale);

		Matrix3x3 getMatrix();
	};
}