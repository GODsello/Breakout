#pragma once

const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 768;

const int FPS = 60;
const int TICKS_PER_FRAME = 1000 / FPS;

struct {
	float width = 15.0f;
	float height = 15.0f;
} ballConstants;

struct {
	float width = 150.0f;
	float height = 20.0f;
} playerConstants;

enum {
	SMALL_FONT = 28,
	MEDIUM_FONT = 36,
	BIG_FONT = 48
};

enum {
	MAIN_ONE_PLAYER,
	MAIN_QUIT,
};

enum {
	RESUME,
	QUIT,
};