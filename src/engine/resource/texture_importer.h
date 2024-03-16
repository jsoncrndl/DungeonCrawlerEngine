#pragma once

#include <string>
#include "../graphics/texture.h"

namespace Engine::Resources
{
	class TextureImporter
	{
		
	public:
		static bool loadResource(Graphics::Texture& texture, std::string fileLocation);
	};
}