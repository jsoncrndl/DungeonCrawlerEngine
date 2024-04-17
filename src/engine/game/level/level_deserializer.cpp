#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rttr/type.h>
#include "level_deserializer.h"

namespace Engine::Game
{
    void LevelDeserializer::loadComponent(Level* level, rapidjson::Value& json)
    {
        assert(json["type"].IsString());
        std::string type = json["type"].GetString();
        assert(rttr::type::get_by_name(type).is_derived_from(rttr::type::get<ECS::Component>()));
        

        assert(json["guid"].IsString());
        xg::Guid guid = xg::Guid(json["guid"].GetString());

        ObjectPoolBase* pool = level->getComponentPool(type);
        assert(pool != nullptr);

        rttr::instance reflectedPool = rttr::instance::instance(pool);
        rttr::variant obj = reflectedPool.get_type().get_method("getObject").invoke(reflectedPool);
        
        ECS::Component* component = obj.get_value<ECS::Component*>();
        m_objects[guid] = component;

        // set object properties
        for (auto& property : json["properties"].GetObject())
        {
            loadProperty(component, guid, property.name.GetString(), property.value);
        }
    }

    void LevelDeserializer::loadEntities(Level* level, rapidjson::Value& json)
    {
        assert(json.IsArray());
        for (rapidjson::Value& entity : json.GetArray())
        {
            ECS::Entity* entity = level->getEntityPool()->getObject();
            if (entity == nullptr)
            {
                std::cout << "Out of entities in the pool! Oh no!";
                break;
            }

            //Check GUID

            if (json.HasMember("name"))
            {
                rapidjson::Value& nameValue = json["name"];
                assert(nameValue.IsString());
                entity->setName(nameValue.GetString());
            }
        }
    }

    void LevelDeserializer::loadProperty(ECS::Component* component, const xg::Guid& componentGuid, const std::string& name, rapidjson::Value& value)
    {

        rttr::instance componentInstance = rttr::instance::instance(component);


        if (value.IsInt())
        {
            componentInstance.get_type().get_property(name).set_value(componentInstance, value.GetInt());
        }
        else if (value.IsFloat())
        {
            componentInstance.get_type().get_property(name).set_value(componentInstance, value.GetFloat());
        }
        else if (value.IsString())
        {
            componentInstance.get_type().get_property(name).set_value(componentInstance, value.GetString());
        }
        else if (value.IsObject())
        {
            // Check if it is an inline struct or an object reference with guid
            //m_references[componentGuid].push_back(PropertyInstance(componentInstance.get_type().get_property(name.GetString()), componentInstance));
        }
        else if (value.IsArray())
        {
        }

    }

    void LevelDeserializer::linkReferences()
    {
        for (auto& reference : m_references)
        {
            PooledObject* obj = m_objects[reference.first];
            for (auto& propertyInstance : reference.second)
            {
                propertyInstance.property.set_value(propertyInstance.instance, obj);
            }
        }
    }

    bool LevelDeserializer::loadLevel(Level* level, std::string serializedLevel)
	{
        rapidjson::Document d;

        if (d.Parse(serializedLevel.c_str()).HasParseError())
        {
            std::cerr << rapidjson::GetParseError_En(d.GetParseError()) << "\n";
            std::cerr << "Error parsing json: " << serializedLevel << "\n";
            return false;
        }

        // Load settings
        // Load components
        // Load entities
        // Link references
        // Load which systems are used
	}
    LevelDeserializer::PropertyInstance::PropertyInstance(rttr::property property, rttr::instance instance) : property(property), instance(instance)
    {
    }
}