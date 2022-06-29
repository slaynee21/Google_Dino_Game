#pragma once

#include <SFML/Graphics.hpp>
#include"cAbsClass.h"

using namespace sf;

class cPlayer:public AbstractClass
{
public:

	cPlayer(Texture& DinoTexture, Texture& IconGameOverTexture, Texture& Fieldtexture, Texture& TitleGameOverTexture);

		void BonusTaken() override {}
		void Intersection(std::vector<Sprite>& VectorOfSprites, Sprite& DinoSprite, int& life, float& timer, bool& GameOver, int& CactControllar, int& ObjCounter) override {}
		void Movement(float time, int SpeedMultipler, Sprite& VectorOfSprites) override{}
		void Animation(float time, Sprite &sprite) override;

		float dy;
		bool onGround;
		int GameStatus, ground;

		Sprite DinoSprite;
		Sprite FieldSprite;
		Sprite IconGameOverSprite;
		Sprite TitleGameOverSprite;

private:

	float dx, curFrame;
	FloatRect rect;
	Texture DinoTexture;

};

