#pragma once
#include <string>
#include "../graphics/shader.h"
namespace Engine::Resources
{
	class ShaderImporter
	{
		friend class Resources::ShaderImporter;
	public:
		static std::shared_ptr<Graphics::Shader> loadResource(const ResourceLocation& registryLocation, std::string fileLocation);
	};
}