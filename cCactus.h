#pragma once

#include "cAbsClass.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class cCactus:public AbstractClass
{public:
	cCactus();
	void BonusTaken() override{}
	void Intersection(std::vector<Sprite>& VectorOfSprites, Sprite& DinoSprite, int& life, float& timer, bool& GameOver, int& CactControllar, int& ObjCounter) override;
	void Movement(float time, int SpeedMultipler, Sprite &VectorOfSprites) override;
	void Animation(float time, Sprite &Sprite) override{}

	int CactusRandNumber = rand() % 6 + 1;
	Sprite CactusSprite[6];
private:
	Texture CactusTexture[6];
};

