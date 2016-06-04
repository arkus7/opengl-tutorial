#include "Mesh.h"
#include <vector>

Mesh::Mesh(Vertex * vertices, unsigned int numVertices)
{
	drawCount = numVertices;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> textureCoords;

	positions.reserve(numVertices);
	textureCoords.reserve(numVertices);

	for (unsigned int i = 0; i < numVertices; i++) {
		positions.push_back(*vertices[i].getPosition());
		textureCoords.push_back(*vertices[i].getTextureCoord());
	}

	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

	// POSITIONS

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW); // GL_STREAM_DRAW

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// TEXTURE COORDS

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXTURE_COORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(textureCoords[0]), &textureCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

void Mesh::draw()
{
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}
