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

		GLuint vertices;
		GLuint texCoords;
		GLuint indices;
		GLuint vao;

		// Define data
		static float vertexArray[];
		static float texCoordsArray[];
		static GLubyte indexArray[];

		static std::shared_ptr<Quad> create();
	};

	class QuadBuffer
	{
		friend class Graphics;

		static std::shared_ptr<QuadBuffer> create(uint8_t size);

	};
}