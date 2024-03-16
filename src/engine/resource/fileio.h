#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <functional>

namespace Engine::IO
{
	inline std::vector<uint8_t> readFile(std::string filePath)
	{
		std::ifstream file(filePath, std::ios::binary);
		if (!file.is_open())
		{
			std::cerr << "Error opening file " << filePath << std::endl;
		}
		else
		{
			std::cout << "File found!" << std::endl;
		}

		file.seekg(0, std::ios::end); // Seek to 0 bytes from the end
		std::streampos length = file.tellg(); // Get the length of the stream from the current position
		file.seekg(0, std::ios::beg); // Seek back to the beginning of the stream

		char* buffer = new char[length];
		file.read(buffer, length);

		file.close();

		std::vector<uint8_t> data(length);
		std::memcpy(data.data(), buffer, length);

		return data;
	}

	inline std::string readText(std::string filePath)
	{
		std::ifstream file(filePath, std::ios::binary);
		if (!file.is_open())
		{
			std::cerr << "Error opening file " << filePath << std::endl;
		}
		else
		{
			std::cout << "File found!" << std::endl;
		}

		file.seekg(0, std::ios::end); // Seek to 0 bytes from the end
		std::streampos length = file.tellg(); // Get the length of the stream from the current position
		file.seekg(0, std::ios::beg); // Seek back to the beginning of the stream

		char* buffer = new char[length];
		file.read(buffer, length);

		file.close();

		return std::string(buffer);
	}

	/// <summary>
	/// Returns a list of all files in the given path, recursively searching directories.
	/// </summary>
	inline std::vector<std::string> getAllFilesRecursive(std::string directoryPath)
	{
		std::vector<std::string> foundPaths;

		for (auto& file : std::filesystem::recursive_directory_iterator(directoryPath))
		{

			if (file.is_regular_file())
			{
				foundPaths.push_back(file.path().string());
			}
		}

		return foundPaths;
	}
}