#include "MainMenu.h"

MainMenu::MainMenu(Font* font)
{
	this->font = font;
	title = font->CreateTexture(BIG_FONT, "BREAKOUT", { 255, 255, 255 });
	onePlayer = font->CreateTexture(SMALL_FONT, "PLAY", { 255, 255, 255 });
	quit = font->CreateTexture(SMALL_FONT, "QUIT", { 255, 255, 255 });
	onePlayerSelected = font->CreateTexture(SMALL_FONT, "PLAY", { 0, 0, 0 }, { 255, 255, 255 });
	quitSelected = font->CreateTexture(SMALL_FONT, "QUIT", { 0, 0, 0 }, { 255, 255, 255 });

	ResetMenu();
}

MainMenu::~MainMenu()
{
	font->ClearTexture(title);
	font->ClearTexture(onePlayer);
	font->ClearTexture(onePlayerSelected);
	font->ClearTexture(quit);
	font->ClearTexture(quitSelected);
	title = nullptr;
	onePlayer = nullptr;
	onePlayerSelected = nullptr;
	quit = nullptr;
	quitSelected = nullptr;

	font = nullptr;
}

int MainMenu::HandleMenuEvents(SDL_Event* e)
{
	if (e->type == SDL_KEYDOWN && (e->key.keysym.sym == SDLK_w || e->key.keysym.sym == SDLK_UP))
	{
		selected--;
		selected = selected < 0 ? 1 : selected;
	}

	if (e->type == SDL_KEYDOWN && (e->key.keysym.sym == SDLK_s || e->key.keysym.sym == SDLK_DOWN))
	{
		selected++;
	}
	selected %= 2;

	if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_RETURN)
	{
		return selected;
	}

	return -1;
}

void MainMenu::RenderMenu()
{
	font->RenderTexture(title,
		SCREEN_WIDTH / 2.0f - title->width / 2.0f,
		SCREEN_HEIGHT * (1.5f / 5.0f));

	if (selected == MAIN_ONE_PLAYER) {
		font->RenderTexture(onePlayerSelected,
			SCREEN_WIDTH / 2.0f - onePlayerSelected->width / 2.0f,
			SCREEN_HEIGHT * (2.5f / 5.0f));
	}
	else {
		font->RenderTexture(onePlayer,
			SCREEN_WIDTH / 2.0f - onePlayer->width / 2.0f,
			SCREEN_HEIGHT * (2.5f / 5.0f));
	}

	if (selected == MAIN_QUIT) {
		font->RenderTexture(quitSelected,
			SCREEN_WIDTH / 2.0f - quitSelected->width / 2.0f,
			SCREEN_HEIGHT * (3.5f / 5.0f));
	}
	else {
		font->RenderTexture(quit,
			SCREEN_WIDTH / 2.0f - quit->width / 2.0f,
			SCREEN_HEIGHT * (3.5f / 5.0f));
	}
}
