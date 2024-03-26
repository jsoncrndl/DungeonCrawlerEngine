#include "material.h"

namespace Engine::Graphics
{
	const std::shared_ptr<Shader>& Material::getShader() const
	{
		return m_shader;
	}
}
