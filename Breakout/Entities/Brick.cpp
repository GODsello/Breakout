#include "Brick.h"

Brick::Brick(unsigned int id,
	float xPos, float yPos, float width, float height,
	unsigned int r, unsigned int g, unsigned int b,
	unsigned int points, Score *score)
	:GameObject(id, xPos, yPos, width, height)
{
	rect.x = xPos;
	rect.y = yPos;
	rect.w = width;
	rect.h = height;

	exists = true;
	this->points = points;
	this->score = score;

	this->r = r;
	this->g = g;
	this->b = b;
}

Brick::~Brick()
{

}

void Brick::Render(SDL_Renderer* renderer)
{
	if (exists)
	{
		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
}

void Brick::Update()
{

}

void Brick::OnCollision(GameObject *collision)
{
	exists = false;
	rect.x = -1;
	rect.y = -1;
	rect.w = 0;
	rect.h = 0;

	score->AddPlayerScore(this->points);
}