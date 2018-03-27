#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#pragma once

class EventListener
{
public:
	EventListener() {}
	~EventListener() {}

	bool W = false;
	bool A = false;
	bool S = false;
	bool D = false;
	bool ARROW_UP = false;
	bool ARROW_DOWN = false;
	bool ARROW_LEFT = false;
	bool ARROW_RIGHT = false;
};

#endif