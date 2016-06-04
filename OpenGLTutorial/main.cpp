#include <iostream>
#include <GL\glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

int main(int argc, char** argv) {
	Display display(800, 600, "Hello World");

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");

	while (!display.isClosed())
	{
		display.clear(0.0f, 0.075f, 0.15f, 1.0f);
		mesh.draw();
		shader.bind();
		texture.bind(0);
		display.update();
	}
	return 0;
}