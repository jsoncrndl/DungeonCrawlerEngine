#pragma once

#include <memory>
#include <string>
#include "shader.h"
#include "unordered_map"

namespace Engine::Graphics
{
	class Material
	{
		const std::shared_ptr<Shader> m_shader;
		//std::unordered_map<std::string, int> // Properties

	public:
		const std::shared_ptr<Shader>& getShader() const;
		// More methods for setting property values
	};
}