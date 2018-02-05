//
//	SDLGameObject.h
//
//

#ifndef __SDLGameObject__
#define __SDLGameObject__

#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:

	SDLGameObject(const LoaderParams* pParams);

	int getX();
	int getY();

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual char getType();

protected:

	int m_x;
	int m_y;

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;

	char m_type;

	std::string m_textureID;

};
#endif
