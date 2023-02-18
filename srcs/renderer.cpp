#include "renderer.h"

#include <map>

#include <SDL2/SDL_image.h>

#include "utility.h"
#include "window.h"

#define ERR_LOAD_TEXTURE "can\'t load an image"
#define ERR_CREATE_TEXTURE "can\'t create texture"

#define SPR_PATH "data/sprites/"
#define SPR_EXT ".png"

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

void Texture::DrawCentered (float x, float y, 
                            int offsX, int offsY, 
                            float angle)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	
	srcRect.x = TILE_SIZE * offsX;
	srcRect.y = TILE_SIZE * offsY;
	srcRect.w = TILE_SIZE;
	srcRect.h = TILE_SIZE;
	dstRect.x = x - TILE_SIZE * 0.5;
	dstRect.y = y - TILE_SIZE * 0.5;
	dstRect.w = TILE_SIZE;
	dstRect.h = TILE_SIZE;

	SDL_RenderCopyEx(Window::renderer, tex, &srcRect, 
	                 &dstRect, angle, nullptr, 
	                 SDL_FLIP_NONE);
}

void Texture::Draw (float x, float y, 
                    int offsX, int offsY, 
                    float angle)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	
	srcRect.x = TILE_SIZE * offsX;
	srcRect.y = TILE_SIZE * offsY;
	srcRect.w = TILE_SIZE;
	srcRect.h = TILE_SIZE;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = TILE_SIZE;
	dstRect.h = TILE_SIZE;

	SDL_RenderCopyEx(Window::renderer, tex, &srcRect, 
	                 &dstRect, angle, nullptr, 
	                 SDL_FLIP_NONE);
}

// ---------------<Texture End>-------------- //

std::map<std::string, Texture *> textureMap;

Texture *LoadTexture (std::string name, std::string path)
{
	if (textureMap[name] == nullptr) {
		textureMap[name] = new Texture(path);
	}
	return textureMap[name];
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