//
//	GameObject.cpp
//
//

#include "GameObject.h"

/* -- load() - Sets values declared in GameObject.h to be used by draw() -- */
void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;

	m_currentRow = 1;
	m_currentFrame = 1;
}

/* -- draw() - Uses values set in load() to draw object to screen -- */
void GameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width,
		m_height, m_currentRow, m_currentFrame, pRenderer);
}

/* -- update() - Simple update function to move object -- */
void GameObject::update()
{
	m_x += 1;
}