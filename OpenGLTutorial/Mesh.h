#pragma once

#include <glm\glm.hpp>
#include <GL\glew.h>
#include "obj_loader.h"

class Vertex
{
public:
	Vertex(const glm::vec3& position, const glm::vec2& textureCoord) {
		this->position = position;
		this->textureCoord = textureCoord;
	}

	inline glm::vec3* getPosition() { return &position; }
	inline glm::vec2* getTextureCoord() { return &textureCoord; }

private:
	glm::vec3 position;
	glm::vec2 textureCoord;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndicies);
	Mesh(const std::string& fileName);
	void draw();
	virtual ~Mesh();
private:

	void initMesh(const IndexedModel& model);

	enum {
		POSITION_VB,
		TEXTURE_COORD_VB,
		INDEX_VB,
		NUM_BUFFERS
	};

	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS];
	unsigned int drawCount;
};

