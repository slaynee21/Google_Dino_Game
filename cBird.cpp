#include "cBird.h"


cBird::cBird() {
	BirdTexture.loadFromFile("Paint/Ptic.png");
	BirdSprite.setTexture(BirdTexture);
}


void cBird::Animation(float time, Sprite &sprite) {
	BirdAnimationFrame += 0.0025 * time;
	if (BirdAnimationFrame > 2)
		BirdAnimationFrame -= 2;
	sprite.setTextureRect(IntRect(93 * int(BirdAnimationFrame), 0, 93, 80));
}

void cBird::Intersection(std::vector<Sprite>& VectorOfSprites, Sprite& DinoSprite, int& life, float& timer, bool& GameOver, int& BirdController, int& ObjCounter) {
	Vector2f vBirdGetPosition = VectorOfSprites.front().getPosition();

	if (life == 1 && DinoSprite.getGlobalBounds().intersects(VectorOfSprites.front().getGlobalBounds())) {
		life--;
		GameOver = true;
		timer = 0;
		BirdController = 0;
	}

	else if (life != 0 && DinoSprite.getGlobalBounds().intersects(VectorOfSprites.front().getGlobalBounds())) {
		life--;
		VectorOfSprites.pop_back();
		ObjCounter = 0;
		BirdController = 0;
	}

	if (vBirdGetPosition.x < -100) {
		VectorOfSprites.pop_back();
		ObjCounter = 0;
		BirdController = 0;
	}
}

void cBird::Movement(float time, int SpeedMultipler, Sprite& VectorOfSprites) {
		VectorOfSprites.move(-0.4 * time - 0.05 * SpeedMultipler * time, 0);
}





