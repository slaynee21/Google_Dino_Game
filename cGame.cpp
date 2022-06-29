#include "cGame.h"
#include<vector>

cGame::cGame() {

	RenderWindow window(VideoMode(1000, 500), "Game");

	DinoTexture.loadFromFile("Paint/Dinosaur.png");
	IconGameOverTexture.loadFromFile("Paint/GameOver.png");
	Fieldtexture.loadFromFile("Paint/pol.png");
	TitleGameOverTexture.loadFromFile("Paint/Naz.png");

	cPlayer DinoPlayer(DinoTexture, IconGameOverTexture, Fieldtexture, TitleGameOverTexture);//przyklad inicjalizacji z konstruktorem z parametrami
	cCactus cactus;
	cScore score;
	cBird bird;
	cHeartBonus HeartBonus;
	cScoreBonus ScoreBonus;


	srand(time(NULL));
	Clock clock;

	while (window.isOpen()) {
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		timer += 0.005;


		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
					window.close();
				break;
			}
		}




		if (Keyboard::isKeyPressed(Keyboard::Space))

			if (DinoPlayer.onGround) {
				if (DinoPlayer.GameStatus < 2) {
					DinoPlayer.dy = -0.4;
					DinoPlayer.onGround = false;

					DinoPlayer.DinoSprite.setTextureRect(IntRect(180, 0, 90, 95));
					DinoPlayer.GameStatus = 1;
				}

				else if (DinoPlayer.GameStatus == 2) {
					DinoPlayer.GameStatus = 1;

					HeartBonus.life=1;
					HeartBonus.HeartSprite.setPosition(1000, 300);
					ScoreBonus.ScoreBonusSprite.setPosition(1000, 300);

					ObjCounter = 0;

					GameOver = false;

					score.ScoreIni();

					if (!VectorOfSprites.empty()) {
						VectorOfSprites.clear();
						VectorOfSprites.shrink_to_fit();//zwalnia nieuzywana pamiec
					}

				}
			}

		if (DinoPlayer.GameStatus == 1 && DinoPlayer.onGround == true)
			play = true;

		if (play) {
			{

				if (ObjCounter < 10) {
					if (CactControllar == 0) {
						cactus.CactusRandNumber = rand() % 6 + 1;
						VectorOfSprites.push_back(cactus.CactusSprite[cactus.CactusRandNumber - 1]);
						if (cactus.CactusRandNumber - 1 < 3) {
							VectorOfSprites.front().setPosition(1000, 395);
						}
						else if (cactus.CactusRandNumber - 1 >= 3) {
							VectorOfSprites.front().setPosition(1000, 370);
						}
						CactControllar = 1;

					}
					cactus.Movement(time, SpeedMultipler, VectorOfSprites.front());
					cactus.Intersection(VectorOfSprites, DinoPlayer.DinoSprite, HeartBonus.life, timer, GameOver, CactControllar, ObjCounter);
					//jeden wariant realizacji skrzyzowania

				}

				


				else if (ObjCounter == 10) {
					if (BirdController == 0) {
						VectorOfSprites.push_back(bird.BirdSprite);
						VectorOfSprites.front().setTextureRect(IntRect(0, 0, 93, 80));
						VectorOfSprites.front().setPosition(1000, 380 - 100 * ((bird.BirdRandPosition = rand() % 2 + 1) - 1));

						BirdController = 1;
					}
					bird.Movement(time, SpeedMultipler, VectorOfSprites.front());
					bird.Animation(time, VectorOfSprites.front());
					bird.Intersection(VectorOfSprites, DinoPlayer.DinoSprite, HeartBonus.life, timer, GameOver, BirdController, ObjCounter);
				}
			}



			if (timer > 330) {
				HeartBonus.Movement(time, SpeedMultipler, HeartBonus.HeartSprite);
				Vector2f vHeartBonusGetPosition = HeartBonus.HeartSprite.getPosition();

				if (vHeartBonusGetPosition.x < -100)
				{
					HeartBonus.HeartSprite.setPosition(1000, 300);
					SpeedMultipler++;
					timer = 0;
				}
				else if (DinoPlayer.DinoSprite.getGlobalBounds().intersects(HeartBonus.HeartSprite.getGlobalBounds())) {
					SpeedMultipler++;
					HeartBonus.HeartSprite.setPosition(1000, 300);
					HeartBonus.BonusTaken();
					timer = 0;
				}
				//drugi wariant realizacji skrzyzowania
			}
			if (timer > 200 && timer < 230) {
				ScoreBonus.Movement(time, SpeedMultipler, ScoreBonus.ScoreBonusSprite);
				Vector2f vScoreBonusGetPosition = ScoreBonus.ScoreBonusSprite.getPosition();
				if (vScoreBonusGetPosition.x < -100)
				{
					ScoreBonus.ScoreBonusSprite.setPosition(1000, 300);
					timer = 231;
				}
				else if (DinoPlayer.DinoSprite.getGlobalBounds().intersects(ScoreBonus.ScoreBonusSprite.getGlobalBounds())) {
					ScoreBonus.ScoreBonusSprite.setPosition(1000, 300);
					ScoreBonus.BonusTaken();
					timer = 231;
				}
			}
			score.ScoreSet(time, ScoreBonus.ScoreMultiplier);

		}
	
			if (GameOver) {
				DinoPlayer.GameStatus = 2;
				timer = 0;
				play = false;
				ScoreBonus.ScoreMultiplier = 1;
				SpeedMultipler = 0;
				VectorOfSprites.push_back(DinoPlayer.IconGameOverSprite);
				VectorOfSprites[1].setPosition(300, 200);
				VectorOfSprites.push_back(DinoPlayer.TitleGameOverSprite);
				VectorOfSprites[2].setPosition(450, 250);
				score1 = score.ScoreCounter[0] + score.ScoreCounter[1] * 10 + score.ScoreCounter[2] * 100 + score.ScoreCounter[3] * 1000 + score.ScoreCounter[4] * 10000;
				if (score1 > score2) {
					score2 = score1;
				}
			}

			HeartBonus.Animation(time, HeartBonus.HeartSprite);
			DinoPlayer.Animation(time, DinoPlayer.DinoSprite);

			window.clear(Color::White);
			window.draw(DinoPlayer.DinoSprite);
			window.draw(HeartBonus.HeartSprite);
			window.draw(ScoreBonus.ScoreBonusSprite);
			for (int i = 0; i < VectorOfSprites.size(); i++) {
				window.draw(VectorOfSprites[i]);
			}
			if (ScoreBonus.ScoreMultiplier == 5) {
				ScoreBonus.Animation(time, ScoreBonus.ScoreBonusSprite);
				ScoreBonus.DrawScoreBonus(window);
				if (ScoreBonus.ScoreCounter < 0) {
					ScoreBonus.ScoreMultiplier = 1;
				}
			}
			HeartBonus.drawHeart(window);
			window.draw(DinoPlayer.FieldSprite);
			for (int i = 0; i < 5; i++)
				window.draw(score.NumberSprite[i]);
			window.display();
		}


	}

	cGame::~cGame() {
		{
			std::cout << "*******************************************" << std::endl << "*               LEADERBOARD               *" << std::endl << "*******************************************" << std::endl;    //Operator <<
			std::cout << "*1.xXx_N00bKilLeR_1337_xXx: 9999999       *" << std::endl << "*                                         *" << std::endl;
			std::cout << "*2.-_-BigB0ss-_- : 99992                  *" << std::endl << "*                                         *" << std::endl;
			std::cout << "*3. _XxX_PuSsY_DeStR0YeR_228_XxX_: 99987  *" << std::endl << "*                                         *" << std::endl;
			std::cout << "*4.___Bad_____B0y____: 99974              *" << std::endl << "*                                         *" << std::endl;
			std::cout << "*5. t0rmented s0ul: 42069                 *" << std::endl << "*...                                      *" << std::endl << "*******************************************" << std::endl << std::endl;
			std::cout << "999. Your Best Score: " << score2 << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		} 

	}
