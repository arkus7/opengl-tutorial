#include <iostream>
#include <GL\glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv) {
	Display display(WIDTH, HEIGHT, "Hello World");

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	Shader shader("./res/basicShader");
	Texture texture("./res/text.jpg");
	Transform transform;
	Camera camera(glm::vec3(0, 0, -2), 70.0f, (float) WIDTH / (float) HEIGHT, 0.1f, 1000.0f);

	float counter = 0.0f;

	while (!display.isClosed())
	{
		display.clear(0.0f, 0.075f, 0.15f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cos(counter);

		transform.getPosition().x = sinCounter;
		transform.getPosition().z = cosCounter;
		transform.getRotation().z = counter;
		transform.getRotation().y = counter;
		transform.getRotation().x = counter;

		shader.bind();
		texture.bind(0);
		shader.update(transform, camera);
		mesh.draw();

		display.update();

		counter += 0.0001f;
	}
	return 0;
}