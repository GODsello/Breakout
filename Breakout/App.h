#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include <vector>
#include <string>
#include <sstream>

#include "Window.h";
#include "GameObject/GameObject.h";
#include "Entities/Ball.h";
#include "Entities/Player.h";
#include "Entities/Brick.h";
#include "Score.h";
#include "Menus/Pause.h";
#include "Menus/MainMenu.h";
#include "Constants.h";

class App
{
public:
	App();
	~App();

	/*
		Creates window and initializes systems
	*/
	bool OnInit();

	/*
		Updates entities
	*/
	void OnUpdate();

	/*
		Game loop
	*/
	void OnLoop();

	/*
		Main menu loop
		Returns option selected
	*/
	int OnMainMenuLoop();

	/*
		Check collisions between entities
	*/
	void CheckCollisions();

	/*
		Destroys entities, window and systems
	*/
	void OnShutdown();

	/*
		Handles keyboard events
	*/
	void HandleEvents();

	/*
		Resets game state.
	*/
	void ResetState(bool win);

	/*
		Adds entities to the vector of entities
	*/
	void LoadEntities();

	/*
		Removes entities from the vector of entities
	*/
	void DeleteEntities(bool removeAll);

private:
	/*
		Checks if the ball has gone out
	*/
	bool CheckLoss();

	/*
		Checks if all bricks were removed
	*/
	bool CheckWin();

	void GenerateLifeTexture();

	Window* window;
	float deltaTime;
	
	Player* player;
	Ball* ball;
	unsigned int life;

	std::vector<GameObject*> entities;
	Score* score;
	Font* font;
	Pause* pauseMenu;
	MainMenu* mainMenu;

	LTexture* lifeTexture;
	std::ostringstream lifeText;

	bool hasLoss;
	bool hasMoved;
	bool pause;
	bool loadBricks;
};

