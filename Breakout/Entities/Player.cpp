#include "Player.h"

Player::Player(unsigned int id,
	float xPos, float yPos, float width, float height, float velocity)
	:GameObject(id, xPos, yPos, width, height)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->velocity = velocity;
	rect.x = xPos;
	rect.y = yPos;
	rect.w = width;
	rect.h = height;
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Player::Update()
{

}

void Player::MoveLeft(float deltaTime)
{
	xPos -= velocity * deltaTime;
	if (xPos < 0) {
		xPos = 0;
	}
	rect.x = xPos;
}

void Player::MoveRight(float deltaTime)
{
	xPos += velocity * deltaTime;
	if (xPos + rect.w > SCREEN_WIDTH) {
		xPos = SCREEN_WIDTH - rect.w;
	}
	rect.x = xPos;
}

void Player::OnCollision(GameObject *collision) 
{

}