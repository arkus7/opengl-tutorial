#pragma once

#include <string>
#include <GL/glew.h>
#include "Transform.h"

class Shader
{
public:
	Shader(const std::string& fileName);

	void bind();
	void update(const Transform& transform);

	GLuint createShader(const std::string & text, GLenum shaderType);

	std::string loadShader(const std::string & fileName);

	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage);

	virtual ~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;

	enum {
		TRANSFORM_UNIFORM,

		NUM_UNIFORMS
	};

	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];
};

