#include "asset_manager.h"
#include "../engine.h"

namespace Engine::Resources
{
	void AssetManager::LoadEngineAssets()
	{
		if (m_shaders.count("engine") > 0)
		{
			std::cout << "Engine has already been loaded!";
		}
		else
		{
			m_shaders["engine"] = std::make_shared<ShaderRegistry>(ResourceLocation("engine", "shaders"));
			m_textures["engine"] = std::make_shared<TextureRegistry>(ResourceLocation("engine", "textures"));
		}
	}

	void AssetManager::LoadGameAssets(Game::Game* game)
	{

	}


	void AssetManager::UnloadEngineAssets()
	{
		Engine::RuntimeEngine::Engine.getGraphics()->freeShaders(m_shaders["engine"]);
	}

	void AssetManager::UnloadGameAssets(Game::Game* game)
	{
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

	const std::shared_ptr<AssetManager::ShaderRegistry> AssetManager::getShaders(std::string project)
	{
		return m_shaders[project];
	}

	const std::shared_ptr<AssetManager::TextureRegistry> AssetManager::getTextures(std::string project)
	{
		return m_textures[project];
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