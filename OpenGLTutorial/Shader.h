#pragma once

#include <string>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);

	void bind();

	GLuint createShader(const std::string & text, GLenum shaderType);

	std::string loadShader(const std::string & fileName);

	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage);

	virtual ~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;

	GLuint program;
	GLuint shaders[NUM_SHADERS];
};

