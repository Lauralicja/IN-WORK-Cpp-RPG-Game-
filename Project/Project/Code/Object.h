#pragma once

#include "Game.h"

class Object
{
public:


	void Update();
	void Render();

	Object(const char* tex, int x, int y);
	~Object();



private:

	int xPos;
	int yPos;

	SDL_Texture* objTex;
	SDL_Rect srcRect, destRect;


};

