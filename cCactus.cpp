#include "cCactus.h"
#include <SFML/Graphics.hpp>


cCactus::cCactus() {

	CactusTexture[0].loadFromFile("Paint/Cact/1.png");
	CactusTexture[1].loadFromFile("Paint/Cact/2.png");
	CactusTexture[2].loadFromFile("Paint/Cact/3.png");
	CactusTexture[3].loadFromFile("Paint/Cact/4.png");
	CactusTexture[4].loadFromFile("Paint/Cact/5.png");
	CactusTexture[5].loadFromFile("Paint/Cact/6.png");

	for (int i = 0; i < 6; i++) {
		CactusSprite[i].setTexture(CactusTexture[i]);
	}
}

void cCactus::Movement(float time, int SpeedMultipler, Sprite &VectorOfSprites)  {
	VectorOfSprites.move(-0.35 * time- 0.05*SpeedMultipler*time, 0);
}

void cCactus::Intersection(std::vector<Sprite>& VectorOfSprites, Sprite& DinoSprite, int& life, float& timer, bool& GameOver, int& CactControllar, int& ObjCounter) {
	Vector2f vCactGetPosition = VectorOfSprites.front().getPosition();


	if (life == 1 && DinoSprite.getGlobalBounds().intersects(VectorOfSprites.front().getGlobalBounds())) {
		life--;
		timer = 0;
		GameOver = true;
		CactControllar = 0;
	}
	else if (life != 0 && DinoSprite.getGlobalBounds().intersects(VectorOfSprites.front().getGlobalBounds())) {
		life--;
		VectorOfSprites.pop_back();
		ObjCounter++;
		CactControllar = 0;
	}

	if (vCactGetPosition.x < -100) {
		VectorOfSprites.pop_back();
		CactControllar = 0;
		ObjCounter++;
	}
}


