//
//	Player.cpp
//
//

#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

/* -- draw() - Uses SDLGameObject's draw function to screen -- */
void Player::draw()
{
	SDLGameObject::draw();
}

/* -- update() - Simple update function to move object -- */
void Player::update()
{
	m_x -= 1;	// Override GameObject::update()
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}

void Player::clean()
{
}