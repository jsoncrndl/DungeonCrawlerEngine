#include "registry.h"

namespace Engine::Resources
{
    ResourceLocation::ResourceLocation(std::string name)
    {
        

    }

    ResourceLocation::ResourceLocation(std::string project, std::string location) : project(project), location(location)
    {
    }

    std::string ResourceLocation::string()
    {
        return project + ":" + location;
    }
}