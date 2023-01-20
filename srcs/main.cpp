#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "utility.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void loadLocation (int locID, std::vector<std::vector<int>> *loc)
{

}

int main(int argc, char* args[]) {
	// SDL_Window* window = NULL;
	// SDL_Surface* screenSurface = NULL;
	// if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	//     fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
	//     return 1;
	// }
	// window = SDL_CreateWindow(
	//             "hello_sdl2",
	//             SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	//             SCREEN_WIDTH, SCREEN_HEIGHT,
	//             SDL_WINDOW_SHOWN
	//             );
	// if (window == NULL) {
	//     fprintf(stderr, "could not create window: %s\n", SDL_GetError());
	//     return 1;
	// }
	// screenSurface = SDL_GetWindowSurface(window);
	// SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	// SDL_Delay(2000);
	// SDL_UpdateWindowSurface(window);
	// SDL_DestroyWindow(window);
	// SDL_Quit();

	vec2 a;
	vec2 b(3, 4);
	vec2 c;

	c = a+b;
	std::cout << "a + b = " << c.x << ' ' << c.y << '\n';
	c = a-b;
	std::cout << "a - b = " << c.x << ' ' << c.y << '\n';
	c = 2*b;
	std::cout << "2 * b = " << c.x << ' ' << c.y << '\n';
	c = b/2;
	std::cout << "b / 2 = " << c.x << ' ' << c.y << '\n';
	c = -b;
	std::cout << "-b = " << c.x << ' ' << c.y << '\n';
	std::cout << "b = " << b[0] << ' ' << b[1] << '\n';

	return 0;
}