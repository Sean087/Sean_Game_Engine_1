//
//	Tile.cpp
//
//

#include "Tile.h"
#include "CollisionManager.h"

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
Tile::Tile(int x, int y, int tileType)
{
	//Get the offsets
	mBox.x = x;
	mBox.y = y;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = tileType;
}

void Tile::render(SDL_Rect& camera, LoadTileTexture &tile, SDL_Renderer *rend, SDL_Rect TileClips[12])
{
	//If the tile is on screen
	if (CollisionManager::Instance()->checkCollision(camera, mBox))
	{
		//Show the tile
		tile.render(mBox.x - camera.x, mBox.y - camera.y, rend, &TileClips[mType]);
	}
}

int Tile::getType()
{
	return mType;
}

SDL_Rect Tile::getBox()
{
	return mBox;
}