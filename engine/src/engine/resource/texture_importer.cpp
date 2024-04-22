#include "texture_importer.h"
#include <filesystem>

namespace Engine::Resources
{
    // Check if the texture is valid. Most loading is done later by the graphics engine
    std::shared_ptr<Graphics::Texture> TextureImporter::loadResource(const ResourceLocation& registryLocation, std::string fileLocation)
    {
        bool isPNG = std::filesystem::path(fileLocation).extension() == ".png";
        return isPNG ? std::shared_ptr<Graphics::Texture>(new Graphics::Texture()) : nullptr;
    }
}