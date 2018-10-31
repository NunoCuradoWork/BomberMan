#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {

public:

	Game(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Game();

	
	void handleEvents();
	void update();
	void render();


	bool runnable() { return isRunning; };

	static SDL_Renderer *renderer;

private:

	
	bool isRunning;
	SDL_Window *window;

};