#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>
#include "EventListener.h"
#include "InputManager.h"
#include "GameTime.h"
#include <chrono>
#include <iostream>
#include "Node.h"
#include "Semaphore.h"
#include "Player.h"
#include "GameWorld.h"
#include "Enemy.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	bool Init();
	void Update();
	void Render();

private:
	bool gameRunning;
	GameTime* gameTime;
	float last;
	float current;
	SDL_Window* m_window;
	SDL_Surface* m_surface;
	SDL_Event m_event;

	int screenWidth;
	int screenHeight;

	EventListener* m_eventListener;
	InputManager* m_input;

	//Map
	GameWorld* gameWorld;

	//Threading
	int Num_Threads;
	vector<SDL_Thread*> SDLThreadPool;
};
