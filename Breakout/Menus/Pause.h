#pragma once

#include "../Font/Font.h";

class Pause
{
public:
	Pause(Font* font);
	~Pause();

	int HandleMenuEvents(SDL_Event* e);
	void RenderMenu();
	void ResetMenu() { selected = RESUME; };

private:
	Font* font;
	LTexture* title;
	LTexture* resume;
	LTexture* quit;
	LTexture* resumeSelected;
	LTexture* quitSelected;

	int selected;

};

