#include "Game.h"

#undef main
int main()
{
	Game* game = new Game();

	game->Init();

	game->Update();

	return 0;
}