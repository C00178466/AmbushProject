#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* r, const char* filename)
{
	tex = IMG_LoadTexture(r, filename);
	rect.x = rect.y = 200;
	rect.w = 32;
	rect.h = 32;

	velocity.x = 0;
	velocity.y = 0;
}

Enemy::~Enemy() {}

void Enemy::Update()
{

}

void Enemy::Render(SDL_Renderer* r)
{
	SDL_RenderCopy(r, tex, NULL, &rect);
}

//pass in current enemy (enemy.at(i)), and the vector of enemies
Point2D Enemy::Alignment(Enemy * currentEnemy, vector<Enemy*>* enemyVector)
{
	Point2D tempVelocity = Point2D(0, 0);
	int neighbourCount = 0;
	float neighboourDist = 50;

	for (int i = 0; i < enemyVector->size(); i++)
	{
		if (enemyVector->at(i) != currentEnemy)
		{
			tempVelocity.x = enemyVector->at(i)->getPos().x;
			tempVelocity.y = enemyVector->at(i)->getPos().y;
			neighbourCount++;
		}
	}

	if (neighbourCount == 0)
	{
		return tempVelocity;
	}

	tempVelocity.x /= neighbourCount;
	tempVelocity.y /= neighbourCount;
	//tempVelocity.Normalize(1);

	return tempVelocity;
}

void Enemy::FindPath(Point2D& startPos)
{

}