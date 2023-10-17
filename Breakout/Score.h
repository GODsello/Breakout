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

	/*
		Renders score text texture
	*/
	void RenderScore();


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

	Font* font;
	LTexture* texture;

	std::ostringstream scoreText;
};

