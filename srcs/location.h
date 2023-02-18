#ifndef LOCATION_H
#define LOCATION_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "utility.h"
#include "renderer.h"
#include "window.h"

class Location;

// this class determines and draws 
// visible area of the map
class Scene {
private:
	SDL_Rect boundary;
	vec2 offsets;

	const Location *loc;

public:
	Scene (const Location *location);
	
	void Update ();

	// function which determines rendering logic
	// (rendering order, screen coordinates of objects, etc)
	void Draw ();
};

// this container stores game level
// TODO: overall entities support 
class Location {
private:
	uint sizeX;
	uint sizeY;
	uint **mtx;
	Scene *scene;

	// texture atlas with all tiles
	Texture* atlas;

	void Load (uint id);
	void Drop ();

public:

	Location (uint id);
	~Location ();

	void Update ();
	void Draw();

	friend Scene;
};

#endif