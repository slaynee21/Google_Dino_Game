#include "cScoreBonus.h"


cScoreBonus::cScoreBonus() {
	ScoreBonusTexture.loadFromFile("Paint/ScoreBonus2.png");
	ScoreBonusSprite.setTexture(ScoreBonusTexture);
	ScoreBonusSprite.scale(0.2, 0.2);
	ScoreBonusSprite.setPosition(1000, 400);

	ScoreBonusTimerTexture.loadFromFile("Paint/Numbers.png");
	ScoreTimer.setTexture(ScoreBonusTimerTexture);
	ScoreTimer.setTextureRect(IntRect(0, 0, 20, 24));
	ScoreTimer.setPosition(58, 42);

	ScoreBonusStatusTexture.loadFromFile("Paint/ScoreBonus.png");
	ScoreBonusStatusSprite.setTexture(ScoreBonusStatusTexture);
	ScoreBonusStatusSprite.setPosition(17, 44);
	ScoreBonusStatusSprite.scale(0.19, 0.22);

}

void cScoreBonus::Animation(float time, Sprite & sprite) {
	ScoreCounter -= 0.002 * time;
	if (ScoreCounter < 10) {

		ScoreTimer.setTextureRect(IntRect(20 * int(ScoreCounter), 0, 20, 44));
	}

}

void cScoreBonus::Movement(float time, int SpeedMultipler, Sprite& VectorOfSprites) {
	ScoreBonusSprite.move(-0.6 * time - 0.05 * SpeedMultipler * time, 0);
}

void cScoreBonus::BonusTaken() {
	ScoreCounter = 10;
	ScoreMultiplier = 5;
}

void cScoreBonus::DrawScoreBonus(RenderWindow& window) {
		window.draw(ScoreBonusStatusSprite);
		window.draw(ScoreTimer);
}