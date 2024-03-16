#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>
#include <memory>
#include <array>

#include "../graphics/texture.h"
#include "fileio.h"

namespace Engine::Resources
{
	struct ResourceLocation
	{
		std::string project;
		std::string location;

		ResourceLocation(std::string name);
		ResourceLocation(std::string project, std::string location);

		std::string string();
	};

	template <typename T, typename I>
	concept ResourceImporter = requires(bool b, T & t)
	{
		b = I::loadResource(t, "");
	};

	template <typename T, typename I>
		requires ResourceImporter<T, I>
	class Registry
	{
		using Importer = I;
		friend Importer;
		ResourceLocation m_name;

		std::unordered_map<std::string, T> m_entries;

	public:
		Registry(ResourceLocation name);
		void load();
		std::unordered_map<std::string, T> entries();
		T* get(std::string location);
		std::string getContentPath();
		std::string getLocation();
	};

	template <typename T, typename I>
		requires ResourceImporter<T, I>
	Registry<T, I>::Registry(ResourceLocation name) : m_name(name)
	{

	}

	template <typename T, typename I>
		requires ResourceImporter<T, I>
	inline void Registry<T, I>::load()
	{
		std::string registryPath = getContentPath();
		std::vector<std::string> paths = IO::getAllFilesRecursive(registryPath);

		for (const std::string& path : paths)
		{
			T resource;

			bool result = Importer::loadResource(resource, path);

			if (result)
			{

				std::filesystem::path relative = std::filesystem::relative(path, registryPath);
				std::string fileName = relative.replace_extension().string();


				m_entries[fileName] = std::move(resource);
			}
		}
	}
	template<typename T, typename I>
		requires ResourceImporter<T, I>
	inline std::unordered_map<std::string, T> Registry<T, I>::entries()
	{
		return m_entries;
	}

	template<typename T, typename I>
		requires ResourceImporter<T, I>
	inline T* Registry<T, I>::get(std::string location)
	{
		if (m_entries.count(location) == 0)
		{
			return nullptr;
		}
		else
		{
			return &(m_entries[location]);
		}	
	}

	template<typename T, typename I>
		requires ResourceImporter<T, I>
	inline std::string Registry<T, I>::getLocation()
	{
		return m_name;
	}

	template<typename T, typename I>
		requires ResourceImporter<T, I>
	inline std::string Registry<T, I>::getContentPath()
	{
		return (std::filesystem::current_path() / "resources" / m_name.project / m_name.location).string();
	}
}