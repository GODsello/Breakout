#include "Score.h"

Score::Score(Font* font)
{
	playerScore = 0;
	bricksRemoved = 0;
	this->font = font;
	UpdateScoreText();
}

Score::~Score()
{
	ClearTexture();
	font = nullptr;
}

void Score::AddPlayerScore(int score)
{
	bricksRemoved++;
	playerScore += score;
	UpdateScoreText();
}

void Score::ResetScore()
{
	playerScore = 0;
	bricksRemoved = 0;
	UpdateScoreText();
}

void Score::ResetBricks()
{
	bricksRemoved = 0;
}

void Score::RenderScore()
{
	font->RenderTexture(texture, 
						(SCREEN_WIDTH / 2.0f) - (texture->width / 2.0f),
						0);
}

void Score::ClearTexture()
{
	if (texture != NULL)
	{
		font->ClearTexture(texture);
		texture = nullptr;
	}
}

void Score::UpdateScoreText()
{
	scoreText.str("");
	scoreText.clear();
	scoreText << playerScore;
	ClearTexture();
	texture = font->CreateTexture(MEDIUM_FONT, scoreText.str(), { 255, 255, 255 });
}
