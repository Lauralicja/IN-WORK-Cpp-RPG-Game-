#pragma once

#include "Game.h"

class TexHandler {

public:

	static SDL_Texture* LoadTex(const char* name);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
	static void DestroyTex(SDL_Texture* tex);

	TexHandler();
	~TexHandler();

};
