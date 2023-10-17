#include "GameObject.h"

GameObject::GameObject(unsigned int id,
	float xPos, float yPos, float width, float height)
{
	this->id = id;
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;
}

//TODO: remove from list
GameObject::~GameObject()
{
	this->xPos = 0.0f;
	this->yPos = 0.0f;
	this->width = 0.0f;
	this->height = 0.0f;
}