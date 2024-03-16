#pragma once

namespace Engine::Graphics
{
	class Shader
	{
		friend class Graphics;
		friend class Resources::ShaderImporter;

		std::string vertSource;
		std::string fragSource;

		uint32_t programID;
	};
}