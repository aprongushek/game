#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class Texture {
private:
	SDL_Texture *tex;

public:
	Texture (std::string path);
	~Texture ();

	void DrawCentered (float x, float y, 
	                   int offsX, int offsY, 
	                   float angle);
	void Draw (float x, float y, 
	           int offsX, int offsY, 
	           float angle);
};

Texture *LoadTexture (std::string name, std::string path);
void DropTexture (std::string name);
void DropAllTextures ();

#endif