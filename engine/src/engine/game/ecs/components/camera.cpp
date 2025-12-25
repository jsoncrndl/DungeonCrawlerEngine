#include "camera.h"

namespace Engine::Game::ECS
{
	Matrix3x3 Camera::getProjectionMatrix()
	{
		return Matrix3x3({ 2 / m_frustumX, 0, 0, 0, 2 / m_frustumY, 0, 0, 0, 1 });
	}
	void Camera::setFrustum(Vector2 size)
	{
		m_frustumX = size.x;
		m_frustumY = size.y;
	}
	void Camera::setFrustum(float sizeX, float sizeY)
	{
		m_frustumX = sizeX;
		m_frustumY = sizeY;
	}
}