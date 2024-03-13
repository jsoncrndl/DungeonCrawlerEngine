#include "quad.h"
#include "GL/glew.h"

namespace Engine::Graphics {
	Quad::Quad(uint32_t vertices, uint32_t texCoords, uint32_t indices) : vertices(vertices), texCoords(texCoords), indices(indices)
	{
	}

	std::shared_ptr<Quad> Quad::create()
	{

		// Define data
		float vertices[] = {
			-1, -1,
			1, -1,
			1, 1,
			- 1, 1
		};

		float texCoords[] = {
			0, 0,
			1, 0,
			1, 1,
			0, 1
		};

		uint8_t indices[] = {
			 0, 1, 2,
			 0, 2, 3
		};


		// Make buffers and buffer data

		uint32_t vertexBuffer;
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		uint32_t texCoordsBuffer;
		glGenBuffers(1, &texCoordsBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, texCoordsBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		uint32_t indexBuffer;
		glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		return std::shared_ptr<Quad>(new Quad(vertexBuffer, texCoordsBuffer, indexBuffer));
	}
}