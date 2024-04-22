#include <rttr/type.h>
#include "serializable.h"

namespace Engine::Game
{
    Engine::Game::Serializable::Serializable()
    {

    }

    std::string Engine::Game::Serializable::serialize() const
    {
        rttr::instance instance = rttr::instance(this);

        // Loop through all properties. If it is a serializable object, serialize the guid
        for (rttr::property property : instance.get_type().get_properties())
        {
        }

        return std::string();
    }

    void Engine::Game::Serializable::deserialize(const rapidjson::Value& json)
    {
        rttr::instance instance = rttr::instance(this);

        // Loop through json values and deserialize properties


    }
}