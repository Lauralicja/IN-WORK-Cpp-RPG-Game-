#include "TexHandler.h"

SDL_Texture* TexHandler::LoadTex(const char* tex) 
{
	SDL_Surface* tmp = IMG_Load(tex);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::rend, tmp);
	SDL_FreeSurface(tmp);
	return texture;
}

void TexHandler::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Game::rend, tex, &src, &dest, NULL, NULL, flip);
}


void TexHandler::DestroyTex(SDL_Texture * tex)
{
	SDL_DestroyTexture(tex);
}


TexHandler::TexHandler()
{

}
TexHandler::~TexHandler()
{

}