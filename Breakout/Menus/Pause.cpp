#include "Pause.h"

Pause::Pause(Font* font)
{
	this->font = font;
	title = font->CreateTexture(BIG_FONT, "PAUSED", { 255, 255, 255 });
	resume = font->CreateTexture(SMALL_FONT, "RESUME", { 255, 255, 255 });
	quit = font->CreateTexture(SMALL_FONT, "QUIT", { 255, 255, 255 });
	resumeSelected = font->CreateTexture(SMALL_FONT, "RESUME", { 0, 0, 0 }, { 255, 255, 255 });
	quitSelected = font->CreateTexture(SMALL_FONT, "QUIT", { 0, 0, 0 }, {255, 255, 255});
	
	ResetMenu();
}

Pause::~Pause()
{
	font->ClearTexture(title);
	font->ClearTexture(resume);
	font->ClearTexture(resumeSelected);
	font->ClearTexture(quit);
	font->ClearTexture(quitSelected);
	title = nullptr;
	resume = nullptr;
	resumeSelected = nullptr;
	quit = nullptr;
	quitSelected = nullptr;

	font = nullptr;
}

int Pause::HandleMenuEvents(SDL_Event* e)
{
	if (e->type == SDL_KEYDOWN && 
		(e->key.keysym.sym == SDLK_w || e->key.keysym.sym == SDLK_UP ||
			e->key.keysym.sym == SDLK_s || e->key.keysym.sym == SDLK_DOWN))
	{
		selected = selected == RESUME ? QUIT : RESUME;
	}

	if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_RETURN)
	{
		return selected;
	}

	return -1;
}

void Pause::RenderMenu() 
{
	font->RenderTexture(title,
		SCREEN_WIDTH / 2.0f - title->width / 2.0f,
		SCREEN_HEIGHT * (1.5f / 5.0f));
	if (selected == RESUME) {
		font->RenderTexture(resumeSelected,
			SCREEN_WIDTH / 2.0f - resumeSelected->width / 2.0f,
			SCREEN_HEIGHT * (2.5f / 5.0f));
		font->RenderTexture(quit,
			SCREEN_WIDTH / 2.0f - quit->width / 2.0f,
			SCREEN_HEIGHT * (3.5f / 5.0f));
	}
	else {
		font->RenderTexture(resume,
			SCREEN_WIDTH / 2.0f - resume->width / 2.0f,
			SCREEN_HEIGHT * (2.5f / 5.0f));
		font->RenderTexture(quitSelected,
			SCREEN_WIDTH / 2.0f - quitSelected->width / 2.0f,
			SCREEN_HEIGHT * (3.5f / 5.0f));
	}
}
