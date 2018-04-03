#include "GameWorld.h"

GameWorld::GameWorld()
{

}

void GameWorld::Init(SDL_Renderer* r)
{
	int wallPos = MAP_WIDTH / 10;
	//Draw Map Here (all tiles initialized to 0)
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; i < MAP_HEIGHT; i++)
		{
			level[i][j] = 0;
		}
	}

	//Draw Map Outline Walls
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		level[i][0] = 1;
		level[0][i] = 1;
		level[MAP_WIDTH - 1][i] = 1;
		level[i][MAP_WIDTH - 1] = 1;
	}

	//Draw Walls (in 1/3 spaces) (Oh, Hi Trump)
	//First Wall
	for (int i = 0; i < MAP_WIDTH * 7 / 8; i++)
	{
		level[wallPos * 2][i] = 1;
	}

	//Second Wall
	for (int i = MAP_HEIGHT / 7; i < MAP_WIDTH * 10 / 11; i++)
	{
		level[wallPos * 5][i] = 1;
	}

	//Third Wall
	for (int i = MAP_HEIGHT / 9; i < MAP_WIDTH * 10 / 11; i++)
	{
		level[wallPos * 8][i] = 1;
	}

	//Output map to console
	for (int y = 0; y<MAP_WIDTH; y++)
	{
		for (int x = 0; x < MAP_HEIGHT; x++)
		{
			if (level[x][y] == 0)
				cout << "."; //Moveable area
			else if (level[x][y] == 1)
				cout << "O"; //obstacle
		}
		cout << endl;
	}


	m_wallTex = IMG_LoadTexture(r, "Wall.jpg");
	m_groundTex = IMG_LoadTexture(r, "Ground.png");
}

void GameWorld::Update()
{

}

void GameWorld::Render(SDL_Renderer* r)
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			if (MAP_WIDTH < 100)
				temp = { i * 64, j * 64, 64, 64 };
			else
				temp = { i * 32, j * 32, 32, 32 };

			if (level[i][j] == 0) //Ground
			{
				SDL_RenderCopy(r, m_groundTex, NULL, &temp);
			}

			if (level[i][j] == 1) //Wall
			{
				SDL_RenderCopy(r, m_wallTex, NULL, &temp);
			}
		}
	}
}