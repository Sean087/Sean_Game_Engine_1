//
//	main.cpp
//
//

#include "Game.h"
#include <iostream>

// The Game object
//ame* g_game = 0;
bool quit = false;
SDL_Event the_event;	// event for quitting the game when ESC is pressed

int main(int argc, char* argv[])
{
	std::cout << "game init attempt...\n";
	if(TheGame::Instance()->init("Seans Game Framework -  v0.2", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while(TheGame::Instance()->running() && quit == false)
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			SDL_Delay(10); // add the delay

			// Poll to see if ESC key is pressed, if true - break from main loop
			while(SDL_PollEvent(&the_event))
			{
				if(the_event.key.keysym.sym  == SDLK_ESCAPE) quit = true;
				else if(the_event.type == SDL_QUIT) quit = true;
			}
		}// end while
	}// end if
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game closing...\n";
	TheGame::Instance()->clean();

	return 0;
}// end main