#pragma once

#include <SFML/Graphics.hpp>
#include "cAbsClass.h"


using namespace sf;

class cScoreBonus :public AbstractClass
{
public:

	cScoreBonus();

	void BonusTaken() override;
	void Intersection(std::vector<Sprite>& VectorOfSprites, Sprite& DinoSprite, int& life, float& timer, bool& GameOver, int& CactControllar, int& ObjCounter) override{}
	void Movement(float time, int SpeedMultipler, Sprite& VectorOfSprites) override;
	void Animation(float time, Sprite& Sprite) override;
	void DrawScoreBonus(RenderWindow& window);

	Sprite ScoreBonusSprite;

	int ScoreMultiplier = 1;
	float ScoreCounter;
private:
	Sprite ScoreTimer;
	Sprite ScoreBonusStatusSprite;

	Texture ScoreBonusStatusTexture;
	Texture ScoreBonusTimerTexture;
	Texture ScoreBonusTexture;
};

