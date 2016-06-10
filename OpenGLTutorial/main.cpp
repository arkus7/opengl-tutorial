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
	Display display(WIDTH, HEIGHT, "Fish");

	Mesh fish("./res/fish.obj");

	Shader shader("./res/basicShader");
	Texture texture("./res/fish.jpg");
	Transform transform;
	Camera camera(glm::vec3(0, 0, -5), 70.0f, (float) WIDTH / (float) HEIGHT, 0.1f, 1000.0f);

	float counter = 0.0f;

	while (!display.isClosed())
	{
		display.clear(0.0f, 0.075f, 0.15f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cos(counter);

		transform.getPosition().x = sinCounter;
		transform.getPosition().y = cosCounter;
		transform.getPosition().z = cosCounter;
		transform.getRotation().y = sinCounter / 4;

		camera.moveLeft(-0.002f);
		camera.rotateX(0.0004f);

		shader.bind();
		texture.bind(0);
		shader.update(transform, camera);
		fish.draw();
		
		display.handleKeyboarEvent(camera);
		display.update();

		counter += 0.001f;
	}
	return 0;
}