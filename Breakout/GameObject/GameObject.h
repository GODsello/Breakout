#pragma once

#include <vector>
#include <SDL.h>

/*
	Class with the virtual methods that the entities should have
*/
class GameObject
{
public:
	GameObject(unsigned int id,
		float xPos, float yPos, float width, float height);
	~GameObject();

	virtual void Update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;

	virtual void OnCollision(SDL_Rect collision) = 0;

	unsigned int GetId() { return id; }
	SDL_Rect* GetRect() { return &rect; }

protected:
	SDL_Rect rect;

	unsigned int id;
	float xPos, yPos;
	float width, height;
};