#include "Game.h"

const float TRIGGER = 0.2f;

SDL_Renderer* m_renderer;

//Characters
Player* player;
Enemy* enemy;

int numberOfUsers;
Semaphore mutexR;
Semaphore rw;

int ThreadFunction(void * ptr);
int LoadPlayer(void * ptr);
int LoadEnemy(void * ptr);

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
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		printf("SDL_Image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		exit(0);
	}

	screenWidth = 1000;
	screenHeight = 600;

	m_window = SDL_CreateWindow("A*mbush Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
	m_surface = SDL_GetWindowSurface(m_window);

	gameWorld = new GameWorld();
	gameWorld->Init(m_renderer);

	m_eventListener = new EventListener();
	m_input = new InputManager(&m_event, m_eventListener);

	last = 0.0f;
	current = 0.0f;

	gameTime = GameTime::getInstance();
	last = gameTime->running();

	Num_Threads = 5;

	//Create Thread Pool
	for (int i = 0; i < Num_Threads; i++)
	{
		SDL_Thread* temp;

		//first thread in pool
		if (i == 1)
			temp = SDL_CreateThread(LoadPlayer, "FindPathFunction", (void *)NULL);
		if (i == 2)
			temp = SDL_CreateThread(LoadEnemy, "FindPathFunction", (void *)NULL);
		else
			temp = SDL_CreateThread(ThreadFunction, "ThreadFunction", (void *)NULL);

		if (NULL != temp)
		{
			SDLThreadPool.push_back(temp);
		}
	}

	int threadCount = 0;
	vector<SDL_Thread*>::iterator iter;

	for (iter = SDLThreadPool.begin(); iter != SDLThreadPool.end(); iter++)
	{
		int threadReturnValue;

		cout << "Waiting for thread : " << threadCount++ << endl;
		SDL_WaitThread(*iter, &threadReturnValue);
	}

	return true;
}

void Game::Update()
{
	while (gameRunning)
	{
		m_input->HandleInput(gameRunning);

		current = gameTime->running();

		if ((current - last) > TRIGGER)
		{
			gameWorld->Update();
			player->Update(m_eventListener);

			last = current;
		}

		Sleep(500);

		Render();
	}
}

void Game::Render()
{
	SDL_RenderClear(m_renderer);

	//Draw Map
	gameWorld->Render(m_renderer);

	//Draw Player
	player->Render(m_renderer);

	//Draw enemies
	enemy->Render(m_renderer);

	SDL_RenderPresent(m_renderer);
}

//Find path
int ThreadFunction(void * ptr)
{
	while (true)
	{
		P(mutexR); //wait function
		numberOfUsers++; //increase number of users

		if (numberOfUsers == 1)
		{
			P(rw);
			cout << "Entering " << this_thread::get_id() << endl;
		}
		V(mutexR);
		
		//Critical Section

		//find path here??

		P(mutexR);
		numberOfUsers--;

		if (numberOfUsers == 0)
		{
			V(rw);
			cout << "Leaving " << this_thread::get_id() << endl;
		}

		V(mutexR);

		this_thread::sleep_for(chrono::seconds(1));
		return 0;
	}
}

int LoadPlayer(void * ptr)
{
	player = new Player(m_renderer, "Player.png");
	return 0;
}

int LoadEnemy(void * ptr)
{
	enemy = new Enemy(m_renderer, "Enemy.png");
	return 0;
}