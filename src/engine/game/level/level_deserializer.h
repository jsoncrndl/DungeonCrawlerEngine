#pragma once

#include <unordered_map>
#include <crossguid/guid.hpp>
#include <rttr/property.h>
#include "level.h"

namespace Engine::Game
{
	class LevelDeserializer
	{
		struct PropertyInstance
		{
			rttr::property property;
			rttr::instance instance;

			PropertyInstance(rttr::property property, rttr::instance instance);
		};

		std::unordered_map<xg::Guid, std::vector<PropertyInstance>> m_references;
		std::unordered_map<xg::Guid, PooledObject*> m_objects;
		std::unordered_map<ECS::Entity*, std::vector<xg::Guid>> m_entityComponents;

		// Keep track of all and instances of properties that need to be assigned an object reference
		// Loop through all properties and set the refence value to the pointer

	private:
		void loadComponent(Level* level, rapidjson::Value& json);
		void loadEntities(Level* level, rapidjson::Value& json);
		void loadProperty(ECS::Component* component, const xg::Guid& componentGuid, const std::string& name, rapidjson::Value& property);
		void linkReferences();

	public:
		bool loadLevel(Level* level, std::string serializedLevel);
	};
}