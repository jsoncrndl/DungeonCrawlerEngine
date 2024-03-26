#include <GL/glew.h>

#include "quad.h"

namespace Engine::Graphics {

	// Define data
	GLfloat Quad::vertexArray[] = {
		-1, -1,
		1, -1,
		1, 1,
		-1, 1
	};

	GLfloat Quad::texCoordsArray[] = {
		0, 0,
		1, 0,
		1, 1,
		0, 1
	};

	GLubyte Quad::indexArray[] = {
		 0, 1, 2,
		 0, 2, 3
	};

	std::shared_ptr<Quad> Quad::create()
	{
		std::shared_ptr<Quad> quad = std::shared_ptr<Quad>(new Quad());

		// Make buffers and buffer data

		glGenBuffers(1, &quad->vertices);
		glBindBuffer(GL_ARRAY_BUFFER, quad->vertices);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, vertexArray, GL_STATIC_DRAW);

		glGenBuffers(1, &quad->texCoords);
		glBindBuffer(GL_ARRAY_BUFFER, quad->texCoords);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, texCoordsArray, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glGenBuffers(1, &quad->indices);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad->indices);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 6, indexArray, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glGenVertexArrays(1, &quad->vao);
		glBindVertexArray(quad->vao);

		// Set the vertex positions
		const uint32_t aPos = 0;
		const uint32_t aTexCoord = 1;

		glBindBuffer(GL_ARRAY_BUFFER, quad->vertices);
		glEnableVertexAttribArray(aPos);
		glVertexAttribPointer(aPos, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

		glBindBuffer(GL_ARRAY_BUFFER, quad->texCoords);
		glEnableVertexAttribArray(aTexCoord);
		glVertexAttribPointer(aTexCoord, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return quad;
	}
	std::shared_ptr<QuadBuffer> QuadBuffer::create(uint8_t amount)
	{



		return std::shared_ptr<QuadBuffer>();
	}
}