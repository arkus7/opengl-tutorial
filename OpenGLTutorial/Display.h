#pragma once

#include <string>
#include <SDL2\SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();

	void swapBuffers();

private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}

	SDL_Window* window;
	SDL_GLContext glContext;
};

