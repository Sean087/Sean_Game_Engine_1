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

	g_game->init("Seans Game Engine - Version 0.1", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}// end while

	g_game->clean();

	return 0;
}// end main