#include "Display.h"
#include <GL\glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);


	window = SDL_CreateWindow(title.c_str(), 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		width, height, 
		SDL_WINDOW_OPENGL);

	glContext = SDL_GL_CreateContext(window);

	GLenum status = glewInit();

	if (status != GLEW_OK) {
		std::cerr << "Glew failed to initialize" << std::endl;
	}

	closed = false;

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}


Display::~Display()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Display::update() 
{
	SDL_GL_SwapWindow(window);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			closed = true;
		}
	}
}

void Display::handleKeyboarEvent(Camera& camera)
{
	const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
	SDL_Event event;

	float amount = 0.15f;
	float angleAmount = 0.08f;
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{
		if (keyboard_state_array[SDL_SCANCODE_UP] && !(keyboard_state_array[SDL_SCANCODE_DOWN]))
		{
			camera.moveForward(amount);
		}
			
		if (!keyboard_state_array[SDL_SCANCODE_UP] && keyboard_state_array[SDL_SCANCODE_DOWN])
		{
			camera.moveForward(-amount);
		}

		if (keyboard_state_array[SDL_SCANCODE_RIGHT] && !keyboard_state_array[SDL_SCANCODE_LEFT])
		{
			camera.moveLeft(-amount);
		}
			
		if (!keyboard_state_array[SDL_SCANCODE_RIGHT] && keyboard_state_array[SDL_SCANCODE_LEFT])
		{
			camera.moveLeft(amount);
		}

		if (keyboard_state_array[SDL_SCANCODE_A] && !keyboard_state_array[SDL_SCANCODE_D]) {
			camera.rotateX(angleAmount);
		}

		if (!keyboard_state_array[SDL_SCANCODE_A] && keyboard_state_array[SDL_SCANCODE_D]) {
			camera.rotateX(-angleAmount);
		}

		if (keyboard_state_array[SDL_SCANCODE_W] && !keyboard_state_array[SDL_SCANCODE_S]) {
			camera.rotateY(-angleAmount);
		}

		if (!keyboard_state_array[SDL_SCANCODE_W] && keyboard_state_array[SDL_SCANCODE_S]) {
			camera.rotateY(angleAmount);
		}
	}
}

bool Display::isClosed() {
	return closed;
}

void Display::clear(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
