//
//	Enemy.cpp
//
//

#include "Enemy.h"

/* -- load() - Sets values declared in GameObject.h to be used by draw() -- */
void Enemy::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

/* -- draw() - Uses values set in load() to draw object to screen -- */
void Enemy::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

/* -- update() - Simple update function to move object -- */
void Enemy::update()
{
	m_x += 1;	// Override GameObject::update()
	m_y += 1;	// Override GameObject::update()
	m_currentFrame = int(((SDL_GetTicks() / 50) % 4));
}