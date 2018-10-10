#include "Object.h"
#include "TexHandler.h"



Object::Object(const char* tex, int x, int y)
{
	objTex = TexHandler::LoadTex(tex);

	xPos = x;
	yPos = y;
}


Object::~Object()
{
}

void Object::Update()
{

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = xPos;
	destRect.y = yPos;


}

void Object::Render()
{
	SDL_RenderCopy(Game::rend, objTex, &srcRect, &destRect);
}