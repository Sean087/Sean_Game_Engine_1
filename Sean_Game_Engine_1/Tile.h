//
//	Tile.h
//
//

#ifndef __Tile__
#define __Tile__

#include <SDL.h>
#include "LoadTileTexture.h"

//The tile
class Tile
{
public:

	//Initializes position and type
	Tile(int x, int y, int tileType);

	//Shows the tile
	void render(SDL_Rect& camera, LoadTileTexture &tile, SDL_Renderer *rend, SDL_Rect TileClips[12]);

	//Get the tile type
	int getType();

	//Get the collision box
	SDL_Rect getBox();

private:
	//The attributes of the tile
	SDL_Rect mBox;

	//The tile type
	int mType;

};
#endif