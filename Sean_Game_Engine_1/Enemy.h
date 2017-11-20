//
//	Enemy.h
//
//

#ifndef __Enemy__
#define __Enemy__

#include "GameObject.h"

class Enemy : public GameObject // Inherit from GameObject
{
public:

	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	//void clean();
};
#endif