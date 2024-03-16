#include "texture_importer.h"
#include <filesystem>

namespace Engine::Resources
{
    // Check if the texture is valid. Most loading is done later by the graphics engine
    bool TextureImporter::loadResource(Graphics::Texture& texture, std::string fileLocation)
    {
        bool isPNG = std::filesystem::path(fileLocation).extension() == ".png";
        return isPNG;
    }
}