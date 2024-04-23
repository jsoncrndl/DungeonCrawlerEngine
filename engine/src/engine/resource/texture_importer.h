#pragma once

#include <string>
#include "../graphics/texture.h"
#include "registry.h"

namespace Engine::Resources
{
	class TextureImporter
	{
		
	public:
		static std::shared_ptr<Graphics::Texture> loadResource(const ResourceLocation& registryLocation, std::string fileLocation);
	};
}