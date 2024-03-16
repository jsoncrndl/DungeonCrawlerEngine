#pragma once
#include <string>
#include "../graphics/shader.h"
namespace Engine::Resources
{
	class ShaderImporter
	{
	public:
		static bool loadResource(Graphics::Shader& shader, std::string fileLocation);
	};
}