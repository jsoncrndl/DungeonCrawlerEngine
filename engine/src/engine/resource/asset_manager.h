#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "registry.h"
#include "shader_importer.h"
#include "texture_importer.h"
#include "../graphics/shader.h"
#include "../graphics/graphics.h"
#include "../graphics/texture.h"

namespace Engine::Game
{
	class Game;
}

namespace Engine::Resources
{
	class AssetManager
	{
		using ShaderRegistry = Registry<Graphics::Shader, Resources::ShaderImporter>;
		using TextureRegistry = Registry<Graphics::Texture, Resources::TextureImporter>;

		std::unordered_map<std::string, std::shared_ptr<ShaderRegistry>> m_shaders;
		std::unordered_map<std::string, std::shared_ptr<TextureRegistry>> m_textures;

	public:
		
		void LoadEngineAssets();
		void LoadGameAssets(Game::Game* game);

		void UnloadEngineAssets();
		void UnloadGameAssets(Game::Game* game);
		
		void LoadResources();

		const std::shared_ptr<ShaderRegistry> getShaders(std::string project);
		const std::shared_ptr<TextureRegistry> getTextures(std::string project);

		const std::shared_ptr<Graphics::Shader> getShader(const Resources::ResourceLocation& location);
		const std::shared_ptr<Graphics::Texture> getTexture(const Resources::ResourceLocation& location);
	};
}