#pragma once
#include <SFML/Graphics.hpp>
#include"cAbsClass.h"


using namespace sf;


class cBird:public AbstractClass
{

public:


	cBird(); 
	void BonusTaken() override{}
	void Intersection(std::vector<Sprite>& VectorOfSprites, Sprite& DinoSprite, int& life, float& timer, bool& GameOver, int& BirdController, int& ObjCounter) override;
	void Movement(float time, int SpeedMultipler, Sprite& VectorOfSprites) override;
	void Animation(float time, Sprite &Sprite) override;

	Sprite BirdSprite;

	int BirdRandPosition;

private:

	float BirdAnimationFrame = 0;
	Texture BirdTexture;
};

