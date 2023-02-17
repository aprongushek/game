#ifndef LOCATION_H
#define LOCATION_H

#include "utility.h"

class Location;

class Camera {
private:
	vec2 position;
	const Location *loc;

public:
	Camera (const Location *location);
	
	void SetPosition (float x, float y); // temporary function
	const vec2 &GetPosition ();

	void Update ();
};

// container for the game level
// TODO: overall entities support 
class Location {
private:
	uint sizeX;
	uint sizeY;
	uint **mtx;
	Camera *camera;

	void Load (uint id);
	void Drop ();

public:

	Location (uint id);
	~Location ();

	friend void RenderScene (Location& loc);
};


// defined in renderer.cpp
void RenderScene (Location& loc);

#endif