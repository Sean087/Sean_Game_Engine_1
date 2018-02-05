//
//	SDLGameObject.cpp
//
//

#include "SDLGameObject.h"
#include "Game.h"
#include "TextureManager.h"

/* set member variables */
SDLGameObject::SDLGameObject(const LoaderParams * pParams) :
	GameObject(pParams)
{
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_type = pParams->getType();
	
	m_textureID = pParams->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->draw(m_textureID, m_x, m_y,
		m_width, m_height, TheGame::Instance()->getRenderer());
	/*TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
		m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());*/
}

void SDLGameObject::update()
{

}

void SDLGameObject::clean()
{

}

int SDLGameObject::getX()
{
	return m_x;
}

int SDLGameObject::getY()
{
	return m_y;
}

char SDLGameObject::getType()
{
	return m_type;
}