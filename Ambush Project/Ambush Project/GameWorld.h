#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

class GameWorld
{
public:
	GameWorld();
	~GameWorld() {}

	void Init(SDL_Renderer* r);
	void Update();
	void Render(SDL_Renderer* r);

private:
	static const int MAP_HEIGHT = 30;
	static const int MAP_WIDTH = 30;

	int level[MAP_WIDTH][MAP_HEIGHT];

	//Game World Textures
	SDL_Texture* m_wallTex;
	SDL_Texture* m_groundTex;
	SDL_Rect wallRect;
	SDL_Rect groundRect;
	SDL_Rect temp;
};
