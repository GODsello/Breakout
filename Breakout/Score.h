#pragma once

#include <string>
#include <sstream>

#include "Font/Font.h";

class Score
{
public:
	Score(Font* font);
	~Score();

	/*
		Adds 1 to the left player score
	*/
	void AddPlayerScore(int score);

	/*
		Sets both scores to zero
	*/
	void ResetScore();

	void ResetBricks();

	/*
		Renders score text texture
	*/
	void RenderScore();

	unsigned int GetBricksRemoved() { return bricksRemoved; }


private:
	/*
		Destroys font and texture
	*/
	void ClearTexture();

	/*
		Updates score texture to new value
	*/
	void UpdateScoreText();

	unsigned int playerScore;
	unsigned int bricksRemoved;

	Font* font;
	LTexture* texture;

	std::ostringstream scoreText;
};

