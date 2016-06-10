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

	void moveForward(float amount)
	{
		position += forward * amount;
	}

	void moveLeft(float amount)
	{
		position += glm::cross(up, forward) * amount;
	}

	void rotateY(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, forward));

		forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		up = glm::normalize(glm::cross(forward, right));
	}

	void rotateX(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

	void setPosition(glm::vec3 position) {
		this->position = position;
	}

	glm::vec3 getPosition()
	{
		return position;
	}

private:
	glm::mat4 perspectiveMatrix;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
};

