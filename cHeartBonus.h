#pragma once

#include <SFML/Graphics.hpp>
#include"cAbsClass.h"

using namespace sf;

class cHeartBonus:public AbstractClass 
{
public:

	cHeartBonus();

	void BonusTaken() override;
	void Intersection(std::vector<Sprite>& VectorOfSprites, Sprite& DinoSprite, int& life, float& timer, bool& GameOver, int& CactControllar, int& ObjCounter) override{	}
	void Movement(float time, int SpeedMultipler, Sprite& VectorOfSprites) override;
	void Animation(float time, Sprite& Sprite) override;
	void drawHeart(RenderWindow& window);

	int life = 1;

	Sprite HeartSprite;


private:

	Sprite HeartsLeftSprite;
	Sprite NumberHeartsSprite;

	Texture NumerHeartsTexture;
	Texture HeartTexture;
	Texture HeartBonusStatusTexture;





};
