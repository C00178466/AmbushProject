#include "Player.h"

Player::Player(SDL_Renderer* r, const char* filename)
{
	tex = IMG_LoadTexture(r, filename);
	rect.x = rect.y = 100;
	rect.w = 64;
	rect.h = 64;
}

void Player::Update()
{

}

void Player::Render(SDL_Renderer* r)
{
	SDL_RenderCopy(r, tex, NULL, &rect);
}