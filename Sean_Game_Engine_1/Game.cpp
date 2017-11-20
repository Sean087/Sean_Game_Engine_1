//
//	Game.cpp
//
//

#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	// Attempt to initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";

		//init thw window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) // window init success
		{
			std::cout << "Window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "render creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // rendere init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	std::cout << "init success\n";
	m_bRunning = true; // everything initialised successfully, start the main loop

	// Load AnimatedKnight image to be rendered
	if (!TextureManager::Instance()->load("assets/AnimatedKnight.png", "AnimatedKnight", m_pRenderer))
	{
		return false;
	}

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 240, 240, "AnimatedKnight")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 240, 240, "AnimatedKnight")));

	return true;
}// end init

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw colour

	// Loop through objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}// end render

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}// end update

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}// end handleEvents

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}// end clean