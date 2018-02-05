//
//	Player.h
//
//

#ifndef __Player__
#define __Player__

#include "SDLGameObject.h"
#include "Tile.h"

class Player : public SDLGameObject 
{
public:

	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update(int waypointX, int waypointY);
	virtual void clean();
};
#endif