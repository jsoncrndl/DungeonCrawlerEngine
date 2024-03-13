#include <memory>

namespace Engine::Graphics
{

	/// <summary>
	/// A simple quad made from two triangles with coordinates from -1 to 1 and UVs from 0 to 1
	/// </summary>
	class Quad
	{
		friend class Graphics;
	private:

		uint32_t vertices;
		uint32_t texCoords;
		uint32_t indices;

		Quad(uint32_t vertices, uint32_t texCoords, uint32_t indices);

		static std::shared_ptr<Quad> create();
	};
}