// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "game.h"



int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;


	Uint32 frameStart;
	int frameTime;

	Game *game = new Game("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	
	while (game->runnable())
	{

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) 
		{
			SDL_Delay(frameDelay - frameTime);

		}
	}
	delete game;
	return 0;
}
