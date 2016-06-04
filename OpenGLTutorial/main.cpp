#include <iostream>
#include <GL\glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

int main(int argc, char** argv) {
	Display display(800, 600, "Hello World");

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	Shader shader("./res/basicShader");
	Texture texture("./res/text.jpg");
	Transform transform;

	float counter = 0.0f;

	while (!display.isClosed())
	{
		display.clear(0.0f, 0.075f, 0.15f, 1.0f);


		transform.getPosition().x = sinf(counter);
		transform.getRotation().z = counter;
		transform.getScale().x = cosf(counter);

		shader.bind();
		texture.bind(0);
		shader.update(transform);
		mesh.draw();

		display.update();

		counter += 0.0001f;
	}
	return 0;
}