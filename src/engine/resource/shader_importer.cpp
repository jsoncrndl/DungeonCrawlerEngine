#include <filesystem>
#include "shader_importer.h"
#include "fileio.h"

namespace Engine::Resources
{
    bool ShaderImporter::loadResource(Graphics::Shader& shader, std::string fileLocation)
    {
        using namespace std::filesystem;

        if (path(fileLocation).extension() != ".json") return false;

        path vertPath = path(fileLocation).replace_extension(".vert");
        path fragPath = path(fileLocation).replace_extension(".frag");
        
        if (exists(vertPath) && exists(fragPath))
        {
            shader.vertSource = IO::readText(vertPath.string());
            shader.fragSource = IO::readText(fragPath.string());

            // Read .json and search for uniforms

        }

        // Check if the file has .json. Parse the .json to make a list of uniforms.
        // Then search for the corresponding vert and fragment shaders.
        // Read the file text and set the shader source.

        return false;
    }
}