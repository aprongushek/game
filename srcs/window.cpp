#include "window.h"

#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define ERR_INIT_SDL "can\'t init SDL"
#define ERR_CREATE_WINDOW "can\'t create window"
#define ERR_CREATE_RENDERER "can\'t create renderer"
#define ERR_INIT_IMG "can\'t init IMG"

#define SCR_WIDTH 640
#define SCR_HEIGHT 480

SDL_Window *Window::window = nullptr;
SDL_Renderer *Window::renderer = nullptr;
int Window::width = 0;
int Window::height = 0;

Window::Window (std::string name)
{
	width = SCR_WIDTH;
	height = SCR_HEIGHT;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		throw ERR_INIT_SDL;

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	window = SDL_CreateWindow(name.c_str(), 
	                          SDL_WINDOWPOS_UNDEFINED, 
	                          SDL_WINDOWPOS_UNDEFINED, 
	                          width, 
	                          height, 
	                          SDL_WINDOW_SHOWN);
	if (window == nullptr)
		throw ERR_CREATE_WINDOW;

	renderer = SDL_CreateRenderer(window, -1, 
	                              SDL_RENDERER_ACCELERATED |
	                              SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
		throw ERR_CREATE_RENDERER;
	SDL_SetRenderDrawColor(renderer, 
	                       0xFF, 0xFF, 
	                       0xFF, 0xFF);

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		throw ERR_INIT_IMG;
}

Window::~Window ()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	IMG_Quit();
}