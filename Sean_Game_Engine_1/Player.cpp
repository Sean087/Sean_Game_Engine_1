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
void Player::update(int waypointX, int waypointY)
{
		SDLGameObject::update();
			if (getX() != waypointX) {
				if (getX() < waypointX)
					m_x += 1;
				else
					m_x -= 1;
			}

			if (getY() != waypointY) {
				if (getY() < waypointY)
					m_y += 1;
				else
					m_y -= 1;
			}

		//m_x -= 1;	// Override GameObject::update()
		//m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}

void Player::clean()
{
}