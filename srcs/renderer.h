#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "location.h"

class Texture {
private:
	SDL_Texture *tex;

public:
	Texture (std::string path);
	~Texture ();

	void Draw (float x, float y, int offset, float angle);
};

void LoadTexture (std::string name, std::string path);
void DropTexture (std::string name);
void DropAllTextures ();

// function which determines rendering logic
// (rendering order, screen coordinates of objects, etc)
void RenderScene (Location& loc);

#endif