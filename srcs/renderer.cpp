#include "renderer.h"

#include <string>
#include <map>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "utility.h"
#include "window.h"
#include "location.h"

#define ERR_LOAD_TEXTURE "can\'t load an image"
#define ERR_CREATE_TEXTURE "can\'t create texture"

#define SPR_PATH "data/sprites/"
#define SPR_EXT ".png"

#define MAP_THEME_ATLAS "tiles"

#define FLOOR_TILE 0
#define WALL_TILE 1

// --------------<Texture Start>------------- //
Texture::Texture (std::string path)
{
	SDL_Surface * tmpSurface = nullptr;
	std::string fullPath = SPR_PATH + path + SPR_EXT;
    tmpSurface = IMG_Load(fullPath.c_str());
    if (tmpSurface == nullptr)
    	throw ERR_LOAD_TEXTURE;
    tex = SDL_CreateTextureFromSurface(Window::renderer, 
                                       tmpSurface);
    if (tex == nullptr)
        throw ERR_CREATE_TEXTURE;
    SDL_FreeSurface(tmpSurface);
}

Texture::~Texture ()
{
	SDL_DestroyTexture(tex);
}

void Texture::Draw (float x, float y, 
                    int offset, 
                    float angle)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	
	srcRect.x = TILE_SIZE * offset;
	srcRect.y = 0;
	srcRect.w = TILE_SIZE;
	srcRect.h = TILE_SIZE;
	dstRect.x = x - TILE_SIZE / 2;
	dstRect.y = y - TILE_SIZE / 2;
	dstRect.w = TILE_SIZE;
	dstRect.h = TILE_SIZE;

	SDL_RenderCopyEx(Window::renderer, tex, &srcRect, 
	                 &dstRect, angle, nullptr, 
	                 SDL_FLIP_NONE);
}

// ---------------<Texture End>-------------- //

std::map<std::string, Texture *> textureMap;

void LoadTexture (std::string name, std::string path)
{
	if (textureMap[name] == nullptr) {
		textureMap[name] = new Texture(path);
	}
}

void DropTexture (std::string name)
{
	delete textureMap[name];
	textureMap.erase(name);
}

void DropAllTextures ()
{
	for (auto iter = textureMap.begin(); 
	     iter != textureMap.end(); iter++)
		delete iter->second;
	textureMap.clear();
}

void RenderScene (Location& loc)
{
	Texture *floor = textureMap[MAP_THEME_ATLAS];

	vec2 camCoords = loc.camera->GetPosition();
	vec2 offsets(Window::width / 2 - camCoords.x,
	             Window::height / 2 - camCoords.y);

	for (int i = 0; i < loc.sizeY; i++) 
		for (int j = 0; j < loc.sizeX; j++) 
			if (loc.mtx[i][j] == FLOOR_TILE) 
				floor->Draw(offsets.x + (j *
				            TILE_SIZE + TILE_SIZE / 2),
				            offsets.y + (i *
				            TILE_SIZE + TILE_SIZE / 2),
				            0, 0.0);

	// TODO: render effects and entities

	for (int i = 0; i < loc.sizeY; i++)
		for (int j = 0; j < loc.sizeX; j++)
			if (loc.mtx[i][j] == WALL_TILE)
				floor->Draw(offsets.x + (j *
				            TILE_SIZE + TILE_SIZE / 2),
				            offsets.y + (i *
				            TILE_SIZE + TILE_SIZE / 2),
				            loc.mtx[i][j], 0.0);
}