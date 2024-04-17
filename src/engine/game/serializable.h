#include <string>
#include <crossguid/guid.hpp>
#include <rapidjson/document.h>

namespace Engine::Game
{
	class Serializable
	{
		xg::Guid guid;

	public:
		Serializable();

		std::string serialize() const;

		void deserialize(const rapidjson::Value& json);
	};
}