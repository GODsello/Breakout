#pragma once

#include <SDL_ttf.h>

#include <string>

#include "../Constants.h";

struct LTexture {
	SDL_Texture* texture;
	int width;
	int height;
};

class Font
{
public:
	Font(SDL_Renderer* renderer);
	~Font();

	/*
		Loads the different font sizes
	*/
	bool LoadFont();

	/*
		Creates texture with a text
	*/
	LTexture* CreateTexture(int fontSize, std::string text, 
		SDL_Color color, SDL_Color bg = { 0,0,0 });

	void RenderTexture(LTexture* texture, int xPos, int yPos);

	void ClearTexture(LTexture* texture);

private:
	TTF_Font* smallFont;
	TTF_Font* mediumFont;
	TTF_Font* bigFont;

	SDL_Renderer* renderer;
};

