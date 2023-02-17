#include "location.h"

#include <fstream>
#include <string>

#include "utility.h"
#include "renderer.h"

#define ERR_FILE_NOT_FOUND "file not found"

#define LOC_PATH "data/locations/"
#define LOC_EXT ".loc"

#define MAP_THEME_ATLAS "tiles"

// --------------<Camera Start>-------------- //

Camera::Camera (const Location *location) :
	position(vec2(0.0,0.0)), loc(location) {}

void Camera::SetPosition (float x, float y)
{
	position.x = x;
	position.y = y;
}

const vec2 &Camera::GetPosition ()
{
	return position;
}

void Camera::Update () {}

// ---------------<Camera End>--------------- //
// -------------<Location Start>------------- //

void Location::Load (uint id)
{
	std::string idStr = toStr(id);
	std::ifstream fIn(LOC_PATH + idStr + LOC_EXT);
	if (fIn) {
		fIn >> sizeY >> sizeX;

		mtx = new uint*[sizeY];
		for (int i = 0; i < sizeY; i++)
			mtx[i] = new uint[sizeX];
		for (int i = 0; i < sizeY; i++)
			for (int j = 0; j < sizeX; j++)
				fIn >> mtx[i][j];

		fIn.close();
	} else {
		throw ERR_FILE_NOT_FOUND;
	}

	// test version of loading textures
	LoadTexture(MAP_THEME_ATLAS, "tiles/0");
}

void Location::Drop ()
{
	DropAllTextures();

	for (int i = 0; i < sizeY; i++)
		delete[] mtx[i];
	delete[] mtx;
}

Location::Location (uint id)
{
	Load(id);
	camera = new Camera(this);

	camera->SetPosition(sizeX*TILE_SIZE / 2, 
	                    sizeY*TILE_SIZE / 2);
}

Location::~Location ()
{
	Drop();
	delete camera;
}

// --------------<Location End>-------------- //