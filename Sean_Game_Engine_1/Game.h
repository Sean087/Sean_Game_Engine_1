//
//	Game.h
//
//

#ifndef __Game__
#define __Game__

#include <vector>
#include "GameObject.h"

class Game
{
public:

	Game() {}
	~Game() {}

	// Make Game a singleton
	// Create the public instance function
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}

	// Set running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();

	// Function to access the provate running variable
	bool running() { return m_bRunning; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;

	bool m_bRunning;

	// Create the s_pInstance member variable
	static Game* s_pInstance;

};

typedef Game TheGame;

#endif // !__Game__
