#pragma once

#include "../GameObject/GameObject.h"
#include "../Constants.h";
#include <vector>

class Player : public GameObject
{
public:
	Player(unsigned int id,
		float xPos, float yPos, float width, float height,
		float velocity);

	void Render(SDL_Renderer* renderer);
	void Update();

	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);

	SDL_Rect GetRect() { return rect; }

	void OnCollision(SDL_Rect collision);

private:
	float velocity;
	float xPos, yPos;
};

