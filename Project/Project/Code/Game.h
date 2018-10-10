#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <SDL_image.h>
#include <vector>

class CollisionComponent;


class Game
{
public:


	void initializer(const char* title, int x, int y, int width, int height, bool fullscreen);
	void eventHandler();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

	static SDL_Renderer *rend;
	static SDL_Event event;
	static std::vector<CollisionComponent*> colliders;
	static void AddTile(int id, int x, int y);

	Game();
	~Game();

private:
	SDL_Window *window;
	bool isRunning;


};

