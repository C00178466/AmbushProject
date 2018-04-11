#include "Game.h"

/*
Written by: Jason Hannon

Date: 19/03/2018 - 11/04/2018

Description: A program that loads in the player and an enemy 
			 using a thread pool of SDL_Thread.

			 A map of 30x30 is created using an array.

			 The player and enemy are created with threads.
*/

#undef main
int main()
{
	Game* game = new Game();

	game->Init();

	game->Update();

	return 0;
}