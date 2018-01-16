//
//	CollisionManager.h
//
//

#ifndef __CollisionManager__
#define __CollisionManager__

#include <SDL.h>
#include "Tile.h"

class CollisionManager
{
public:

	CollisionManager() {}
	~CollisionManager() {}

	// Make TextureManager a singleton
	// Create the public instance function
	static CollisionManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new CollisionManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	//Box collision detector
	bool checkCollision(SDL_Rect a, SDL_Rect b);

	bool touchesWall(SDL_Rect box, Tile* tiles[]);

private:

	static CollisionManager* s_pInstance;
};
#endif