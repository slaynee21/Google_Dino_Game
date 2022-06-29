#include "cScore.h"

cScore::cScore() {
	NumberTexture.loadFromFile("Paint/Numbers.png");
	for (int i = 0; i < 5; i++) {
		NumberSprite[i].setTexture(NumberTexture);
		NumberSprite[i].setTextureRect(IntRect(0, 0, 20, 24));
		NumberSprite[i].setPosition(950 - 25 * i, 2);
	}
}

void cScore::ScoreIni() {
	for (int i = 0; i < 5; i++) {
		ScoreCounter[i] = 0;
		NumberSprite[i].setTextureRect(IntRect(0, 0, 20, 24));
	}
}


void cScore::ScoreSet(float time, int ScoreMultiplier) {

	ScoreCounter[0] += 0.005 * time * ScoreMultiplier;
	if (ScoreCounter[0] > 10) {
		ScoreCounter[0]-=10;

		ScoreCounter[1]++;
		if (ScoreCounter[1] > 9) {
			ScoreCounter[1] -=10;

			ScoreCounter[2]++;
			if (ScoreCounter[2] > 9) {
				ScoreCounter[2] -=10;

				ScoreCounter[3]++;
				if (ScoreCounter[3] > 9) {
					ScoreCounter[3] -=10;

					ScoreCounter[4]++;
					if (ScoreCounter[4] > 9)
						ScoreCounter[4] -=10;

					NumberSprite[4].setTextureRect(IntRect(20 * int(ScoreCounter[4]), 0, 20, 24));
				}

				NumberSprite[3].setTextureRect(IntRect(20 * int(ScoreCounter[3]), 0, 20, 24));
			}

			NumberSprite[2].setTextureRect(IntRect(20 * int(ScoreCounter[2]), 0, 20, 24));
		}

		NumberSprite[1].setTextureRect(IntRect(20 * int(ScoreCounter[1]), 0, 20, 24));
	}

	NumberSprite[0].setTextureRect(IntRect(20 * int(ScoreCounter[0]), 0, 20, 24));
}
//nie moglem znalezc pliku .ttf w ktorym bylyby te liczby, wiec musialem to zrobic za pomoca array i sprite




