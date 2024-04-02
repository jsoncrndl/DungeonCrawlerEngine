#include "transform.h"

namespace Engine::ECS
{
	Vector2 Transform::getWorldPosition() const
	{
		Vector2 parentPosition;
		if (m_parent == nullptr)
		{
			parentPosition = Vector2(0,0);
		}
		else
		{
			parentPosition = m_parent->getWorldPosition();
		}

		return parentPosition + m_localPosition;
	}

	float Transform::getWorldRotation() const
	{
		float parentRotation;
		if (m_parent == nullptr)
		{
			parentRotation = 0;
		}
		else
		{
			parentRotation = m_parent->getWorldRotation();
		}

		return parentRotation + m_localRotation;
	}

	Vector2 Transform::getLocalPosition() const
	{
		return m_localPosition;
	}

	float Transform::getLocalRotation() const
	{
		return m_localRotation;
	}

	void Transform::setWorldPosition(const Vector2& position)
	{
		Vector2 parentPosition;
		if (m_parent == nullptr)
		{
			parentPosition = Vector2(0, 0);
		}
		else
		{
			parentPosition = m_parent->getWorldPosition();
		}

		m_localPosition = position - parentPosition;
	}

	void Transform::setWorldRotation(const float& rotation)
	{
		float parentRotation;
		if (m_parent == nullptr)
		{
			parentRotation = 0;
		}
		else
		{
			parentRotation = m_parent->getWorldRotation();
		}

		m_localRotation = rotation - parentRotation;
	}

	void Transform::setLocalPosition(const Vector2& localPosition)
	{
		m_localPosition = localPosition;
	}

	void Transform::setLocalRotation(const float& rotation)
	{
		m_localRotation = rotation;
	}

	Transform* Transform::getParent() const
	{
		return m_parent;
	}

	void Transform::setParent(Transform* parent)
	{
		Vector2 previousPosition = getWorldPosition();
		float previousRotation = getWorldRotation();

		m_parent = parent;
		
		if (m_parent != nullptr)
		{
			setWorldPosition(previousPosition);
			setWorldRotation(previousRotation);
		}
	}
	Vector2 Transform::getLocalScale()
	{
		return m_localScale;
	}
	void Transform::setLocalScale(const Vector2& scale)
	{
		m_localScale = scale;
	}
	void Transform::reset()
	{
		m_localPosition = Vector2(0, 0);
		m_localRotation = 0;
		m_localScale = Vector2(0, 0);
		m_parent = nullptr;
	}
}