#include "cPlayer.h"
#include <SFML/Graphics.hpp>



cPlayer::cPlayer(Texture &DinoTexture, Texture &IconGameOverTexture, Texture &Fieldtexture, Texture & TitleGameOverTexture) {

	FieldSprite.setTexture(Fieldtexture);
	FieldSprite.scale(1.2, 1);
	FieldSprite.setPosition(0, 450);

	IconGameOverSprite.setTexture(IconGameOverTexture);
	IconGameOverSprite.setPosition(1000, 0);

	TitleGameOverSprite.setTexture(TitleGameOverTexture);
	TitleGameOverSprite.setPosition(1000, 0);

	DinoSprite.setTexture(DinoTexture);
	DinoSprite.setTextureRect(IntRect(0, 0, 90, 95));

	dx = dy = 0;
	curFrame = 0;
	GameStatus = 0;
	ground = 370;
}

void cPlayer::Animation(float time, Sprite &sprite) {
	rect.left += dx * time;

	if (!onGround)
		dy = dy + 0.0005 * time;

	rect.top += dy * time;

	if (rect.left == 0)
		rect.left = 100;
	if (rect.top == 0)
		rect.top = 370;

	onGround = false;

	if (rect.top > ground) {
		rect.top = ground;
		dy = 0;

		onGround = true;
	}


	DinoSprite.setPosition(rect.left, rect.top);

	dx = 0;
	if (dy == 0) {
		if (GameStatus == 0) {
			curFrame += 0.0005 * time;
			if (curFrame > 1 && curFrame < 1.95)
				curFrame = 1.95;
			if (curFrame > 2)
				curFrame -= 2;
		}

		else if (GameStatus == 1) {
			if (curFrame < 2)
				curFrame = 2;

			curFrame += 0.007 * time;
			if (curFrame > 4)
				curFrame -= 2;
		}

		else if (GameStatus == 2)
			curFrame = 4;

		DinoSprite.setTextureRect(IntRect(90 * int(curFrame), 0, 90, 95));
	}
}
