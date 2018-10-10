#include "Game.h"
#include "TexHandler.h"
#include "Map.h"
#include "CH/CompHandler.h"
#include "CH/Components.h"
#include "Vector2D.h"
#include "CH/KeyboardHandler.h"
#include "Collision.h"



Map* mapka;

SDL_Renderer* Game::rend = nullptr;
SDL_Event Game::event;

std::vector<CollisionComponent*> Game::colliders;

Manager manager;

auto& wall(manager.addEntity());
auto& player(manager.addEntity());

enum groupLabels : size_t
{
	groupMap,
	groupPlayer,
	groupEnemies,
	groupColliders,
	groupItems
};




void Game::initializer(const char * title, int x, int y, int width, int height, bool fullscreen)
{
	int flag = 0;
	if (fullscreen) flag = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, x, y, width, height, flag);
		if (!window) {
			std::cout << "Window broken" << std::endl;
		}
		rend = SDL_CreateRenderer(window, -1, 0);
		if (!rend) {
			std::cout << "Renderer broken" << std::endl;
		}
		isRunning = true;
	}
	else isRunning = false;
	
	mapka = new Map();


	Map::LoadMap("assets/sprites/mapka.map", 64, 64);

	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/sprites/guy.png", true);
	player.addComponent<KeyboardHandler>();
	player.addComponent<CollisionComponent>("player");
	player.addGroup(groupPlayer);

	
	wall.addComponent<TransformComponent>(200.0f, 100.0f, 300, 20, 2);
	wall.addComponent<SpriteComponent>("assets/sprites/dirt.png");
	wall.addComponent<CollisionComponent>("wall");
	wall.addGroup(groupMap);
	
}

void Game::eventHandler()
{
	
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}


auto& tiles(manager.getGroup(groupMap));
auto& playerGrp(manager.getGroup(groupPlayer));
auto& enemies(manager.getGroup(groupEnemies));
auto& collidersGrp(manager.getGroup(groupColliders));

void Game::update()
{
	manager.refresh();
	manager.update();


	for (auto c : tiles)
	{
		if (Collision::AABB(player.getComponent<CollisionComponent>().collider, wall.getComponent<CollisionComponent>().collider)) {
			player.getComponent<TransformComponent>().velocity * -1;
			//wall.destroy();
		}
	}

	//for (auto cc : colliders) // moge tak po kazdym pojechac, jak pominac player?
	//{		
	//	Collision::AABB(player.getComponent<CollisionComponent>(), *cc);	
	//}

}



void Game::render()
{
	SDL_RenderClear(rend);
	//map->DrawMap();
	for (auto& t : tiles)
	{
		t->draw();
	}
	for (auto& p : playerGrp)
	{
		p->draw();
	}
	for (auto& e : enemies)
	{
		e->draw();
	}
	for (auto& c : collidersGrp)
	{
		c->draw();
	}

	SDL_RenderPresent(rend);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(rend);
	SDL_Quit();
}

void Game::AddTile(int id, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 64, 64, id);
	tile.addGroup(groupMap);
}

Game::Game()
{
}


Game::~Game()
{
}
