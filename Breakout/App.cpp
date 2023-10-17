#include "App.h"

App::App(){
	window = new Window();
	player = nullptr;
	ball = nullptr;
	deltaTime = 0.0f;
	hasLoss = false;
	hasMoved = false;
	score = nullptr;
	pause = false;
	font = nullptr;
}

App::~App(){
	OnShutdown();
}

bool App::OnInit()
{
	// Create window
	bool result = window->Init("Pong", SCREEN_WIDTH, SCREEN_HEIGHT);

	font = new Font(window->GetRenderer());
	result = font->LoadFont();
	score = new Score(font);
	mainMenu = new MainMenu(font);
	pauseMenu = new Pause(font);

	return result;
}

void App::OnUpdate()
{
	for(GameObject * g : entities)
	{
		g->Update();
	}
}

void App::OnLoop()
{
	bool quit = false;
	
	SDL_Event event;

	while (!quit)
	{
		if (hasLoss)
		{
			LoadEntities();
		}

		float startTime = SDL_GetTicks();
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			{
				pauseMenu->ResetMenu();
				pause = !pause;
			}
			if (pause)
			{
				int pauseResult = pauseMenu->HandleMenuEvents(&event);
				switch (pauseResult)
				{
				case RESUME:
					pause = false;
					break;
				case QUIT:
					quit = true;
					break;
				default:
					break;
				}
			}
		}

		if (!pause)
		{
			HandleEvents();

			if (hasMoved)
			{
				OnUpdate();

				CheckCollisions();
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(window->GetRenderer(), 0x0, 0x00, 0x00, 0x00);
		SDL_RenderClear(window->GetRenderer());

		score->RenderScore();

		for (GameObject* g : entities)
		{
			g->Render(window->GetRenderer());
		}

		if (pause)
		{
			pauseMenu->RenderMenu();
		}

		SDL_RenderPresent(window->GetRenderer());

		hasLoss = CheckLoss();
		if (hasLoss)
		{
			DeleteEntities();
			hasMoved = false;
		}
		
		// FPS handle
		deltaTime = (SDL_GetTicks() - startTime);
		if (deltaTime < TICKS_PER_FRAME)
		{
			SDL_Delay(TICKS_PER_FRAME - deltaTime);
		}
		deltaTime = (SDL_GetTicks() - startTime);
	}
}

int App::OnMainMenuLoop()
{
	bool stopLoop = false;
	int selected = -1;

	SDL_Event event;

	while (!stopLoop)
	{
		float startTime = SDL_GetTicks();
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				stopLoop = true;
				selected = MAIN_QUIT;
			}
			if (selected < 0)
			{
				selected = mainMenu->HandleMenuEvents(&event);
				if (selected >= 0)
				{
					stopLoop = true;
				}
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(window->GetRenderer(), 0x0, 0x00, 0x00, 0x00);
		SDL_RenderClear(window->GetRenderer());

		mainMenu->RenderMenu();

		SDL_RenderPresent(window->GetRenderer());

		deltaTime = (SDL_GetTicks() - startTime);
		if (deltaTime < TICKS_PER_FRAME)
		{
			SDL_Delay(TICKS_PER_FRAME - deltaTime);
		}
		deltaTime = (SDL_GetTicks() - startTime);
	}
	return selected;
}

void App::CheckCollisions()
{
	for (GameObject* entity1 : entities) {
		for (GameObject* entity2 : entities)
		{
			if (entity1->GetId() == entity2->GetId())
			{
				continue;
			}

			if (SDL_HasIntersection(entity1->GetRect(), entity2->GetRect()))
			{
				entity1->OnCollision(*entity2->GetRect());
			}
		}
	}
}

void App::OnShutdown()
{
	entities.clear();

	delete score;
	score = nullptr;

	delete pauseMenu;
	pauseMenu = nullptr;

	delete font;
	font = nullptr;

	delete window;
	window = nullptr;
}

void App::HandleEvents()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_D])
	{
		player->MoveRight(deltaTime);
		hasMoved = true;
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		player->MoveLeft(deltaTime);
		hasMoved = true;
	}
}

void App::ResetState()
{
	hasLoss = false;
	pause = false;
	hasMoved = false;
	score->ResetScore();
}

void App::LoadEntities() {
	ball = new Ball(entities.size(),
		SCREEN_WIDTH/2.0f - ballConstants.width/2.0f , 
		SCREEN_HEIGHT/2.0f - ballConstants.height/2.0f,
		ballConstants.width, ballConstants.height, 
		0.5f, 
		&deltaTime);
	entities.push_back(ball);

	player = new Player(entities.size(), 
		SCREEN_WIDTH/2.0f - playerConstants.width/2.0f, SCREEN_HEIGHT * (4.5f/5.0f),
		playerConstants.width, playerConstants.height, 
		1.0f);
	entities.push_back(player);
}

void App::DeleteEntities()
{
	for (GameObject* g : entities) {
		delete g;
	}
	entities.clear();

	ball = nullptr;
	player = nullptr;
}

bool App::CheckLoss() 
{
	if (ball->GetRect()->y + ball->GetRect()->h + 1.0 > SCREEN_HEIGHT)
	{
		return true;
	}

	return false;
}