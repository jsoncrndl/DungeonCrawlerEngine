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

	/// <summary>
	/// Reads all text from a file and copies it to outString
	/// </summary>
	/// <param name="filePath">Path of the file to read</param>
	/// <param name="outString">String to copy results to</param>
	/// <returns>True if successful, false on an error</returns>
	inline bool readText(std::string filePath, std::string& outString)
	{
		std::ifstream file(filePath, std::ios::binary);
		if (!file.is_open())
		{
			std::cerr << "Error opening file " << filePath << std::endl;
			return false;
		}

		file.seekg(0, std::ios::end); // Seek to 0 bytes from the end
		std::streampos length = file.tellg(); // Get the length of the stream from the current position
		file.seekg(0, std::ios::beg); // Seek back to the beginning of the stream

		// Not null-terminated buffer
		char* buffer = new char[length];
		file.read(buffer, length);

		file.close();

		// Needs length in constructor because buffer is not null-terminated
		outString = std::string(buffer, length);
		return true;
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