//
//	main.cpp
//
//

#include "Game.h"

// The Game object
Game* g_game = 0;

int main(int argc, char* argv[])
{
	g_game = new Game();

	g_game->init("Seans Game Engine - Version 0.1", 100, 100, 1920, 1080, true);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();

		SDL_Delay(10); // add the delay
	}// end while

	g_game->clean();

	return 0;
}// end main