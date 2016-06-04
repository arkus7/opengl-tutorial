#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Camera
{
public:

	Camera(const glm::vec3& postition, float fov, float aspect, float zNear, float zFar)
	{
		perspectiveMatrix = glm::perspective(fov, aspect, zNear, zFar);
		this->position = position;
		forward = glm::vec3(0, 0, 1); // Z axis
		up = glm::vec3(0, 1, 0); // Y axis
	}

	inline glm::mat4 getViewProjection() const
	{
		return perspectiveMatrix * glm::lookAt(position, position + forward, up);
	}

	virtual ~Camera()
	{
	}

private:
	glm::mat4 perspectiveMatrix;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
};

