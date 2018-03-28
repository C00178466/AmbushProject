#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "EventListener.h"
#include "InputManager.h"
#include "GameTime.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "Node.h"
#include "Semaphore.h"

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
	SDL_Renderer* m_renderer;
	SDL_Event m_event;

	int screenWidth;
	int screenHeight;

	EventListener* m_eventListener;
	InputManager* m_input;
};
