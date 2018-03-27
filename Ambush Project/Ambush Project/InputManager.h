#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#pragma once
#include <SDL.h>
#include "EventListener.h"

class InputManager
{
public:
	InputManager(SDL_Event* e, EventListener* el)
	{
		m_e = e;
		m_eventListen = el;
	}

	~InputManager() {}

	void HandleInput(bool& gameRunning);

private:
	SDL_Event* m_e;
	EventListener* m_eventListen;
};

#endif