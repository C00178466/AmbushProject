#pragma once
#include <Windows.h>
#include <process.h>

class GameTime
{
public:
	~GameTime();

	static GameTime* getInstance();
	float running();

private:
	static GameTime* instance;
	static float total; //total game time

protected:
	GameTime();
};
