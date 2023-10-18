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

	yDir = 0.8f;
	xDir = rand() % 10 < 5 ? -0.5f : 0.5f;
}

void Ball::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

void Ball::OnCollision(GameObject *collision)
{
	if (collision->GetId() == PLAYER_ID)
	{
		velocity += 0.02f;
		float midBall = rect.x + rect.w / 2.0f;
		float midCollided = collision->GetRect()->x + collision->GetRect()->w / 2.0f;

		xDir = midBall < midCollided ? -0.5 : 0.5;
		yDir *= -1;
	}

	if (collision->GetId() == BRICK_ID)
	{
		SDL_Rect collRect = *collision->GetRect();
		float topDiff = abs((rect.y + height) - collRect.y);
		float bottomDiff = abs(rect.y - (collRect.y + collRect.h));
		float leftDiff = abs((rect.x + rect.w) - collRect.x);
		float rightDiff = abs(rect.x - (collRect.x + collRect.w));

		if ((topDiff < bottomDiff && topDiff < leftDiff && topDiff < rightDiff) ||
			(bottomDiff < topDiff && bottomDiff < leftDiff && bottomDiff < rightDiff))
		{
			yDir *= -1;
		}
		else if ((leftDiff < bottomDiff && leftDiff < topDiff && leftDiff < rightDiff) ||
			(rightDiff < topDiff && rightDiff < leftDiff && rightDiff < bottomDiff))
		{
			xDir *= -1;
		}
	}
}