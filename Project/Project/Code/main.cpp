#include "Game.h"
#include "windows.h"
#include "mmsystem.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {

	const int cap = 60;
	const int delay = 1000 / cap;
	Uint32 frameSt;
	int frameTime;

	game = new Game();
	game->initializer("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false);

	while (game->running()) {
		
		//PlaySound(TEXT("C:/Users\\Laura\\source\\repos\\Project\\Project\\assets\\sounds\\sample.wav"), 0, SND_FILENAME);

		frameSt = SDL_GetTicks();

		game->eventHandler();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameSt;

		if (delay > frameTime) SDL_Delay(delay - frameTime);
		
	}
	game->clean();

	return 0;
}