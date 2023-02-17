#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "utility.h"
#include "window.h"
#include "location.h"
#include "renderer.h"

int main(int argc, char* args[]) {
	// std::cout << "HELLO!!!\n"; 
	try {
		Window window("game");
		Location testLoc(0);
		Texture testTex("chars/player/player");
	
		bool run = true;
		while (run) {
			SDL_Event event;
			while(SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					run = false;
				}
			}
	
			RenderScene(testLoc);
			testTex.Draw(120, 120, 0, 45);
	
			SDL_RenderPresent(Window::renderer);
		}
	
	} catch (const char *msg) {
		std::cout << "ERROR::" << msg << '\n';
	}

	return 0;
}