#include "asset_manager.h"


namespace Engine::Resources
{
	void AssetManager::AddProject(std::string name)
	{
		if (m_shaders.count(name) > 0)
		{
			std::cout << "Project with name " << name << " already exists!";
		}
		else
		{
			m_shaders[name] = std::make_shared<ShaderRegistry>(ResourceLocation(name, "shaders"));
			m_textures[name] = std::make_shared<TextureRegistry>(ResourceLocation(name, "textures"));
		}
	}

	void AssetManager::LoadResources()
	{
		// Read project file

		for (const auto& registry : m_textures)
		{
			registry.second->load();
		}

		for (const auto& registry : m_shaders)
		{
			registry.second->load();
		}
	}

	const std::vector<std::shared_ptr<AssetManager::ShaderRegistry>> AssetManager::getShaders()
	{
		std::vector<std::shared_ptr<ShaderRegistry>> shaders;

		for (const auto& kv : m_shaders)
		{
			shaders.push_back(kv.second);
		}

		return shaders;
	}

	const std::vector<std::shared_ptr<AssetManager::TextureRegistry>> AssetManager::getTextures()
	{
		std::vector<std::shared_ptr<TextureRegistry>> textures;

		for (const auto& kv : m_textures)
		{
			textures.push_back(kv.second);
		}

		return textures;
	}
	const std::shared_ptr<Graphics::Shader> AssetManager::getShader(const Resources::ResourceLocation& location)
	{
		return m_shaders[location.getProject()]->get(location.getLocation());
	}
	const std::shared_ptr<Graphics::Texture> AssetManager::getTexture(const Resources::ResourceLocation& location)
	{
		return m_textures[location.getProject()]->get(location.getLocation());
	}
}