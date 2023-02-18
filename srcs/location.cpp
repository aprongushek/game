#include "location.h"

#include <fstream>
#include <string>

#define ERR_FILE_NOT_FOUND "file not found"

#define LOC_PATH "data/locations/"
#define LOC_EXT ".loc"

#define MAP_THEME_ATLAS "atlas"

#define FLOOR_TILE 0
#define WALL_TILE 1

// --------------<Scene Start>-------------- //

Scene::Scene (const Location *location) :
	loc(location) 
{
	boundary.x = 0;
	boundary.y = 0;
	boundary.w = loc->sizeX;
	boundary.h = loc->sizeY;

	offsets.x = 10;
	offsets.y = 80;
}

void Scene::Update () {}

void Scene::Draw () 
{
	for (int i = boundary.y; i < boundary.h; i++) 
		for (int j = boundary.x; j < boundary.w; j++) 
			if (loc->mtx[i][j] == FLOOR_TILE) 
				loc->atlas->Draw(offsets.x+(j*TILE_SIZE),
				                 offsets.y+(i*TILE_SIZE),
				                 0, 0, 0.0);

	// TODO: render entities

	for (int i = boundary.y; i < boundary.h; i++) 
		for (int j = boundary.x; j < boundary.w; j++) 
			if (loc->mtx[i][j] == WALL_TILE) 
				loc->atlas->Draw(offsets.x+(j*TILE_SIZE),
				                 offsets.y+(i*TILE_SIZE),
				                 1, 0, 0.0);
}

// ---------------<Scene End>--------------- //
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
	atlas = LoadTexture(MAP_THEME_ATLAS, "tiles/0");
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
	scene = new Scene(this);
}

Location::~Location ()
{
	Drop();
	delete scene;
}

void Location::Update () {}

void Location::Draw ()
{
	scene->Draw();
}

// --------------<Location End>-------------- //