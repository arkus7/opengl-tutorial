#pragma once

#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);

	void bind();
	void update(const Transform& transform, const Camera& camera);

	GLuint createShader(const std::string & text, GLenum shaderType);

	std::string loadShader(const std::string & fileName);

	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage);

	virtual ~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;

	void initModelToCameraMatrix();

	enum {
		TRANSFORM_UNIFORM,
		MODEL_TO_CAMERA_UNIFORM,
		NUM_UNIFORMS
	};
	float modelToCameraMatrix[16];
	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];
};

