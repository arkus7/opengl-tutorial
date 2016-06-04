#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Camera
{
public:

	Camera(const glm::vec3& position, float fov, float aspect, float zNear, float zFar)
	{
		this->position = position;
		this->forward = glm::vec3(0, 0, 1); // Z axis
		this->up = glm::vec3(0, 1, 0); // Y axis
		this->perspectiveMatrix = glm::perspective(fov, aspect, zNear, zFar);
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

