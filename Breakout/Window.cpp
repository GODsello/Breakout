#include "Window.h"

Window::Window()
{
	width = 0;
	height = 0;
	title = "";
	window = nullptr;
	renderer = nullptr;
}

Window::~Window()
{
	CleanUp();
}

bool Window::Init(const char* title, const int width, const int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return false;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, NULL);
	if (!window)
	{
		printf("Error creating window: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		printf("Error creating renderer: %s\n", SDL_GetError());
		return false;
	}

	this->width = width;
	this->height = height;
	this->title = title;

	return true;
}

void Window::CleanUp()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	width = 0;
	height = 0;
	title = "";
	window = nullptr;
	renderer = nullptr;
}
