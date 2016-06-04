#include "Mesh.h"
#include <vector>
#include "obj_loader.h"

Mesh::Mesh(Vertex * vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndicies)
{
	IndexedModel model;
	for (unsigned int i = 0; i < numVertices; i++)
	{
		model.positions.push_back(*vertices[i].getPosition());
		model.texCoords.push_back(*vertices[i].getTextureCoord());
	}

	for (unsigned int i = 0; i < numIndicies; i++) {
		model.indices.push_back(indices[i]);
	}
	
	initMesh(model);
}

Mesh::Mesh(const std::string & fileName)
{
	IndexedModel model = OBJModel(fileName).ToIndexedModel();
	initMesh(model);
}

void Mesh::draw()
{
	glBindVertexArray(vertexArrayObject);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::initMesh(const IndexedModel & model)
{
	drawCount = model.indices.size();

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

	// POSITIONS

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW); // GL_STREAM_DRAW

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// TEXTURE COORDS

	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXTURE_COORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.texCoords.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	// INDICES

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
}
