#include "Ball.h"

Ball::Ball(unsigned int id,
	float xPos, float yPos, float width, float height, float velocity, float *deltaTime)
	:GameObject(id, xPos, yPos, width, height)
{
	rect.x = xPos;
	rect.y = yPos;
	rect.w = width;
	rect.h = height;

	this->deltaTime = deltaTime;
	this->velocity = velocity;

	srand((unsigned)time(NULL));

	yDir = 1.0f;
	xDir = rand() % 10 < 5 ? -0.75f : 0.75f;
}

void Ball::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Ball::Update()
{
	xPos += xDir * velocity * *deltaTime;
	yPos += yDir * velocity * *deltaTime;


	// Stops ball for getting stuck in the border
	if (yPos < 0.0f)
	{
		yPos = 1.0f;
		yDir *= -1.0f;
	}
	if (xPos < 0.0f)
	{
		xPos = 1.0f;
		xDir *= -1.0f;
	}
	if (xPos + width > SCREEN_WIDTH)
	{
		xPos = SCREEN_WIDTH - width - 1.0f;
		xDir *= -1.0f;
	}

	rect.x = xPos;
	rect.y = yPos;
}

void Ball::OnCollision(SDL_Rect collision)
{
	velocity += 0.03f;
	float midBall = rect.x + rect.w / 2.0f;
	float midCollided = collision.x + collision.w / 2.0f;

	xDir = midBall < midCollided ? -1.0 : 1.0;

	yPos -= yDir * velocity * *deltaTime;
	yDir *= -1;
}