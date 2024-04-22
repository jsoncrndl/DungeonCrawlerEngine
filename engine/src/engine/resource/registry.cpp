#include "registry.h"

namespace Engine::Resources
{
    ResourceLocation::ResourceLocation(std::string name)
    {
        

    }

    ResourceLocation::ResourceLocation(std::string project, std::string location) : project(project), location(location)
    {
    }

    const std::string ResourceLocation::getProject() const
    {
        return project;
    }

    const std::string ResourceLocation::getLocation() const
    {
        return location;
    }

    std::string ResourceLocation::string()
    {
        return project + ":" + location;
    }
}