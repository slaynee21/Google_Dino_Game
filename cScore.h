#pragma once

#include <SFML/Graphics.hpp>
#include <array>

using namespace sf;

class cScore
{
public:
	cScore();

	void ScoreIni();
	void ScoreSet(float time, int ScoreMultiplier);

	Sprite NumberSprite[5];

	std::array<float, 5>ScoreCounter = { 0,0,0,0,0 };
private:
	Texture NumberTexture;
};

