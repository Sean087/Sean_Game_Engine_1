//
//	Player.cpp
//
//

#include "Player.h"

/* -- load() - Sets values declared in GameObject.h to be used by draw() -- */
void Player::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

/* -- draw() - Uses values set in load() to draw object to screen -- */
void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

/* -- update() - Simple update function to move object -- */
void Player::update()
{
	m_x -= 1;	// Override GameObject::update() 
}