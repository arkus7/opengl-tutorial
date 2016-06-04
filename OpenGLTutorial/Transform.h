#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Transform
{
public:
	Transform(const glm::vec3& position = glm::vec3(), const glm::vec3& rotation = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
	position(position),
	rotation(rotation),
	scale(scale) {}

	inline glm::mat4 getModel() const 
	{
		glm::mat4 positionMatrix = glm::translate(position);
		glm::mat4 rotationXMatrix = glm::rotate(rotation.x, glm::vec3(1, 0, 0));
		glm::mat4 rotationYMatrix = glm::rotate(rotation.y, glm::vec3(0, 1, 0));
		glm::mat4 rotationZMatrix = glm::rotate(rotation.z, glm::vec3(0, 0, 1));
		glm::mat4 scaleMatrix = glm::scale(scale);

		// matrix multiplying -> backwards
		glm::mat4 rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;

		return positionMatrix * rotationMatrix * scaleMatrix;
	}

	inline glm::vec3& getPosition() { return position; }
	inline glm::vec3& getRotation() { return rotation; }
	inline glm::vec3& getScale() { return scale; }

	inline void setPosition(const glm::vec3& position) { this->position = position; }
	inline void setRotation(const glm::vec3& rotation) { this->rotation = rotation; }
	inline void setScale(const glm::vec3& scale) { this->scale = scale; }

	virtual ~Transform() {}
private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

