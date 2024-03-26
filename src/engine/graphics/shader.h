#pragma once
#include <vector>
#include <string>
#include <optional>
#include <unordered_map>


namespace Engine::Resources
{
	class ShaderImporter;
}

namespace Engine::Graphics
{
	enum UniformType
	{
		NONE,
		BOOL,
		INT,
		FLOAT,
		VEC2,
		VEC3,
		VEC4,
		VEC2I,
		VEC3I,
		VEC4I,
		MAT2,
		MAT3,
		MAT4,
		SAMPLER2D
		// Sampler value is which texture unit it is sampling. Is set using uniform int
	};
	struct Uniform
	{
		std::string name;
		uint32_t location;
		UniformType type;
	};

	class Shader
	{
		friend class Graphics;
		friend class Resources::ShaderImporter;

		std::string vertSource;
		std::string fragSource;

		uint32_t vertexID;
		uint32_t fragmentID;
		uint32_t programID;

		std::unordered_map<std::string, Uniform> m_uniforms;

		bool isValid;

		const std::optional<Uniform> getUniform(std::string name);
	};
}