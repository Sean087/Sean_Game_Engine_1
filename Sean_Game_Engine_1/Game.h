//
//	Game.h
//
//

#ifndef __Game__
#define __Game__

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:

	Game() {};
	~Game() {};

	// Set running variable to true
	//void init();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void draw();
	void update();
	void handleEvents();
	void clean();

	// Function to access the provate running variable
	bool running() { return m_bRunning; }

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player1;

	GameObject* m_player;
	GameObject* m_enemy1;
	GameObject* m_enemy2;
	GameObject* m_enemy3;

	int m_currentFrame;

	bool m_bRunning;
};

#endif // !__Game__
