#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Types.h"

using namespace std;

class Enemy
{
public:
	Enemy(SDL_Renderer* r, const char* filename);
	~Enemy();

	void Update();
	void Render(SDL_Renderer* r);

	Point2D getPos()
	{
		Point2D temp;
		temp.x = rect.x;
		temp.y = rect.y;

		return temp;
	}

	//Flocking Functions

	//Alignment - to line up with other enemies nearby
	Point2D Alignment(Enemy * currentEnemy, vector<Enemy*>* enemyVector);

	void FindPath(Point2D& startPos);

private:
	SDL_Texture* tex;
	SDL_Rect rect;

	Point2D velocity;
};
