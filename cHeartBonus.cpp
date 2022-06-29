#include "cHeartBonus.h"
#include <SFML/Graphics.hpp>



cHeartBonus::cHeartBonus() {
	HeartTexture.loadFromFile("Paint/heart.png");
	HeartSprite.setTexture(HeartTexture);
	HeartSprite.scale(0.2, 0.2);
	HeartSprite.setPosition(1000, 300);

	HeartBonusStatusTexture.loadFromFile("Paint/HeartBonusStatus.png");
	HeartsLeftSprite.setTexture(HeartBonusStatusTexture);
	HeartsLeftSprite.setPosition(13, 4);
	HeartsLeftSprite.scale(0.13, 0.13);

	NumerHeartsTexture.loadFromFile("Paint/Numbers.png");
	NumberHeartsSprite.setTexture(NumerHeartsTexture);
	NumberHeartsSprite.setPosition(58, 5);
	NumberHeartsSprite.setTextureRect(IntRect(20 * life, 0, 20, 24));

}


void cHeartBonus::Animation(float time, Sprite &sprite) {
	NumberHeartsSprite.setTextureRect(IntRect(20 * life, 0, 20, 24));
}

void cHeartBonus::BonusTaken() {
	life++;
}

void cHeartBonus::Movement(float time, int SpeedMultipler, Sprite&) {
	HeartSprite.move(-0.5 * time - 0.05 * SpeedMultipler * time, 0);
}

void cHeartBonus::drawHeart(RenderWindow& window) {
	window.draw(HeartsLeftSprite);
	window.draw(NumberHeartsSprite);
}



