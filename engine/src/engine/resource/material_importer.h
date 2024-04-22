#pragma once
#include <string>

#include "../graphics/material.h"

namespace Engine::Resources
{
	class MaterialImporter
	{
	public:
		static bool loadResource(Graphics::Material& material, std::string fileLocation);
	};
}