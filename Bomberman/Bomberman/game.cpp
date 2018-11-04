#include "game.h"
#include "textureManager.h"
#include "GameObject.h"
#include "map.h"

#include "ECS.h"
#include "Components.h"

GameObject *player;
GameObject *enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());


Game::Game(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Subsystems Initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Rendered created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	player = new GameObject("assets/bomber.png", 0,0);
	enemy = new GameObject("assets/bomberEnemy.png", 50, 50);
	map = new Map();

	newPlayer.addComponent<PositionComponent>();
	
	
}

Game::~Game()
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}


void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{

	player->Update();
	enemy->Update();
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().getXposition() << "," <<
		newPlayer.getComponent <PositionComponent>().getYposition() << std::endl;

}

void Game::render()
{
	//this is where we would add stuff to render
	
	SDL_RenderClear(renderer);
	map->drawMap();
	player->Render();
	enemy ->Render();
	
	SDL_RenderPresent(renderer);
}




