#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Player
{
public:
	Player() {}
	Player(SDL_Renderer* r, const char* filename);
	~Player() {}

	void Update();
	void Render(SDL_Renderer* r);

private:
	SDL_Texture* tex;
	SDL_Rect rect;
};
