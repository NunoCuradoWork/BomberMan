// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "game.h"



int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Game *game = new Game("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	while (game->runnable())
	{
		game->handleEvents();
		game->update();
		game->render();

	}
	delete game;
	return 0;
}
