#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "cPlayer.h"
#include "cHeartBonus.h"
#include "cAbsClass.h"
#include "cScoreBonus.h"
#include"cCactus.h"
#include"cScore.h"
#include"cBird.h"

using namespace sf;


class cGame {
public:

	cGame();
	~cGame();

	int SpeedMultipler = 0;
	int ObjCounter = 0;
	int BirdController = 0;
	int CactControllar = 0;
	float timer = 0;
	float time;
	int score1,score2;


	std::vector<Sprite> VectorOfSprites;//dynamiczny przydzial pamieci
	bool play = false;
	bool GameOver = false;


private:
	Texture TitleGameOverTexture;
	Texture Fieldtexture;
	Texture DinoTexture;
	Texture IconGameOverTexture;

};





