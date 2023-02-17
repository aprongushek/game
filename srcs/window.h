#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>


class Window {
public:
	static SDL_Window *window;
	static SDL_Renderer *renderer;
	
	static int width;
	static int height;

	Window (std::string name);
	~Window ();
};

#endif