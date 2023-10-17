#pragma once

const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 768;

const int BALL_ID = 0;
const int PLAYER_ID = 1;
const int BRICK_ID = 2;

const int BLOCK_MARGIN = 75;
const int BLOCK_ROWS = 5;
const int BLOCK_COLUMNS = 9;

const int FPS = 60;
const int TICKS_PER_FRAME = 1000 / FPS;

const int COLORS[5][3] = {
	{255, 0, 0},
	{0, 255, 0},
	{0, 0, 255},
	{255, 255, 0},
	{255, 0, 255}
};

struct {
	float width = 15.0f;
	float height = 15.0f;
} ballConstants;

struct {
	float width = 150.0f;
	float height = 20.0f;
} playerConstants;

struct {
	float width = 100.0f;
	float height = 20.0f;
} brickConstants;

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