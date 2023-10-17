#pragma once

#include "../GameObject/GameObject.h"
#include "../Constants.h"
#include "../Score.h"

#include <stdio.h>

class Brick : public GameObject
{
public:
	Brick(unsigned int id,
		float xPos, float yPos, float width, float height, 
		unsigned int r, unsigned int g, unsigned int b,
		unsigned int points, Score *score);
	~Brick();

	void Render(SDL_Renderer* renderer);
	void Update();

	void OnCollision(GameObject *collision);

private:
	unsigned int r, g, b;
	bool exists;
	unsigned int points;
	Score* score;
};

