#include "Game.h"

const float TRIGGER = 0.2f;

Game::Game()
{

}

Game::~Game() {}

bool Game::Init()
{
	gameRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		exit(0);
	}
	/*if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		printf("SDL_Image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		exit(0);
	}*/

	screenWidth = 1000;
	screenHeight = 600;

	m_window = SDL_CreateWindow("A*mbush Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);

	m_eventListener = new EventListener();
	m_input = new InputManager(&m_event, m_eventListener);

	last = 0.0f;
	current = 0.0f;

	gameTime = GameTime::getInstance();
	last = gameTime->running();

	//for (int y = 0; y < m; y++)
	//{
	//	for (int x = 0; x < n; x++)
	//	{
	//		map[x][y] = 0;
	//	}
	//}

	//for (int x = n / 8; x < n * 7 / 8; x++)
	//{
	//	map[x][m / 2] = 1;
	//}

	//for (int y = m / 8; y < m * 7 / 8; y++)
	//{
	//	map[n / 2][y] = 1;
	//}

	////randomly select start and finish locations
	//int xA, yA, xB, yB;
	//xA = 0;
	//yA = 0;
	////xB = n - 1;
	////yB = n - 1;
	//xB = 31;
	//yB = 31;

	//cout << "Map Size (X,Y): " << n << "," << m << endl;
	//cout << "Start: " << xA << "," << yA << endl;
	//cout << "Finish: " << xB << "," << yB << endl;
	//// get the route
	//clock_t start = clock();
	//string route = FindPath(xA, yA, xB, yB);
	//if (route == "") cout << "An empty route generated!" << endl;
	//clock_t end = clock();
	//double time_elapsed = double(end - start);
	//cout << "Time to calculate the route (ms): " << time_elapsed << endl;
	//cout << "Route:" << endl;
	//cout << route << endl << endl;

	//// follow the route on the map and display it 
	//if (route.length()>0)
	//{
	//	int j; char c;
	//	int x = xA;
	//	int y = yA;
	//	map[x][y] = 2;
	//	for (int i = 0; i<route.length(); i++)
	//	{
	//		c = route.at(i);
	//		j = atoi(&c);
	//		x = x + dx[j];
	//		y = y + dy[j];
	//		map[x][y] = 3;
	//	}
	//	map[x][y] = 4;

	//	// display the map with the route
	//	for (int y = 0; y<m; y++)
	//	{
	//		for (int x = 0; x<n; x++)
	//			if (map[x][y] == 0)
	//				cout << ".";
	//			else if (map[x][y] == 1)
	//				cout << "O"; //obstacle
	//			else if (map[x][y] == 2)
	//				cout << "S"; //start
	//			else if (map[x][y] == 3)
	//				cout << "R"; //route
	//			else if (map[x][y] == 4)
	//				cout << "F"; //finish
	//		cout << endl;
	//	}
	//}
	return true;
}

void Game::Update()
{
	while (gameRunning)
	{
		current = gameTime->running();

		if ((current - last) > TRIGGER)
		{
			cout << "Updating" << endl;
			last = current;
		}

		Sleep(500);
		cout << ".";
	}
}

void Game::Render()
{


}