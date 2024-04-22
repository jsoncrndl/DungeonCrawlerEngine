#include <filesystem>
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <unordered_map>

#include "registry.h"
#include "shader_importer.h"
#include "fileio.h"

namespace Engine::Resources
{
    namespace
    {
        constexpr Engine::Graphics::UniformType uniformTypeFromName(std::string name)
        {
            using namespace Engine::Graphics;

            if (name == "int") {
                return UniformType::INT;
            }
            else if (name == "float") {
                return UniformType::FLOAT;
            }
            else if (name == "bool") {
                return UniformType::BOOL;
            }
            else if (name == "ivec2") {
                return UniformType::VEC2I;
            }
            else if (name == "ivec3") {
                return UniformType::VEC3I;
            }
            else if (name == "ivec4") {
                return UniformType::VEC4I;
            }
            else if (name == "vec2") {
                return UniformType::VEC2;
            }
            else if (name == "vec3") {
                return UniformType::VEC3;
            }
            else if (name == "vec4") {
                return UniformType::VEC4;
            }
            else if (name == "mat2") {
                return UniformType::MAT2;
            }
            else if (name == "mat3") {
                return UniformType::MAT3;
            }
            else if (name == "mat4") {
                return UniformType::MAT4;
            }
            else if (name == "sampler2D") {
                return UniformType::SAMPLER2D;
            }
            else {
                return UniformType::NONE;
            }
        }

        void loadUniforms(std::string fileLocation, std::unordered_map<std::string, Graphics::Uniform>& uniforms, rapidjson::Document& document)
        {
            rapidjson::Value& value = document["uniforms"];
            if (!value.IsArray())
            {
                std::cerr << "Error reading shader uniforms - " << fileLocation;
                return;
            }
            for (auto& i : value.GetArray())
            {
                Engine::Graphics::Uniform uniform;
                rapidjson::Value& uniformJSON = i.GetObject();
                uniform.name = uniformJSON["name"].GetString();
                uniform.type = uniformTypeFromName(uniformJSON["type"].GetString());

                uniforms[uniform.name] = uniform;
            }
        }
    }

    std::shared_ptr<Graphics::Shader> ShaderImporter::loadResource(const ResourceLocation& registryLocation, std::string fileLocation)
    {
        namespace fs = std::filesystem;


        fs::path registryPath = fs::current_path() / "resources" / registryLocation.getProject() / registryLocation.getLocation();

        if (fs::path(fileLocation).extension() != ".json") return nullptr;

        // Read .json and vert, frag, and uniforms

        std::shared_ptr<Graphics::Shader> shader = std::shared_ptr<Graphics::Shader>(new Graphics::Shader());

        std::string json;

        bool result = IO::readText(fileLocation, json);
        if (!result)
        {
            std::cerr << "Error reading file " << fileLocation;
            return nullptr;
        }

        rapidjson::Document d;

        if (d.Parse(json.c_str()).HasParseError())
        {
            std::cerr << rapidjson::GetParseError_En(d.GetParseError()) << "\n";
            std::cerr << "Error parsing json: " << fileLocation << "\n";
            return nullptr;
        }

        rapidjson::Value& vertValue = d["vert"];
        rapidjson::Value& fragValue = d["frag"];

        fs::path vertPath = registryPath;
        fs::path fragPath = registryPath;

        bool validVert = true;
        bool validFrag = true;

        if (vertValue.IsString())
        {
            vertPath /= vertValue.GetString();
            vertPath.concat(".vert");

            if (!fs::exists(vertPath))
            {
                std::cout << "Couldn't find vertex path " << vertPath << "\n";
                validVert = false;
            }
        }
        else
        {
            std::cerr << "Value for vert key must be a string.";
            validVert = false;
        }

        if (fragValue.IsString())
        {
            fragPath /= fragValue.GetString();
            fragPath.concat(".frag");

            if (!fs::exists(fragPath))
            {
                std::cout << "Couldn't find frag path " << fragPath << "\n";
                validFrag = false;
            }
        }
        else
        {
            std::cerr << "Value for frag key must be a string.";
            validFrag = false;
        }

        if (validVert && validFrag)
        {
            validVert = IO::readText(vertPath.string(), shader->vertSource);
            validFrag = IO::readText(fragPath.string(), shader->fragSource);
        }

        // Load uniforms from json

        loadUniforms(fileLocation, shader->m_uniforms, d);

        return validVert && validFrag ? shader : nullptr;
    }
}