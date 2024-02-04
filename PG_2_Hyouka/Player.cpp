#include "Player.h"
#include "Novice.h"

Player::Player() {

	playerpos_.x = 640.0f;
	playerpos_.y = 500.0f;
	outer_.x = -50;
	outer_.y = -50;
	bulletpos_.x = outer_.x;
	bulletpos_.y = outer_.y;
	playerradius_ = 50.0f;
	speed_ = 5.0f;
	isbullet_ = 0;
	isAlive2 = 0;
	between_.x = 0;
	between_.y = 0;
	reborn2 = 0;
	distance2 = 0;
	bullet = new Bullet;

}

Player::~Player() { delete bullet; }

void Player::PlayerMove(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		playerpos_.y -= speed_;
	}
	if (keys[DIK_A]) {
		playerpos_.x -= speed_;
	}
	if (keys[DIK_S]) {
		playerpos_.y += speed_;
	}
	if (keys[DIK_D]) {
		playerpos_.x += speed_;
	}
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] && isbullet_ == 0) {
		bulletpos_.x = playerpos_.x;
		bulletpos_.y = playerpos_.y;
		bullet->BulletPos_.x = playerpos_.x;
		bullet->BulletPos_.y = playerpos_.y;
		isbullet_ = 1;
		bullet->isShot = true;
	}

	bullet->Update();

}

void Player::Hit(Vector2 player, Vector2 enemy) {
	between_.x = (player.x - enemy.x);
	between_.y = (player.y - enemy.y);
	distance2 = sqrtf((between_.x) * (between_.x)) + sqrtf((between_.y) * (between_.y));
	if (distance2 <= playerradius_ + 30) {
		isbullet_ = 0;
		isAlive2 = 0;

	}
	if (isAlive2 == 0) {
		reborn2++;
		if (reborn2 >= 120) {
			isAlive2 = 1;
		}
	}
}

void Player::PlayerDraw() {
	if (isAlive2 == 1) {
		reborn2 = 0;
		Novice::DrawEllipse((int)playerpos_.x, (int)playerpos_.y, (int)playerradius_, (int)playerradius_, 0, WHITE, kFillModeSolid);
	}

	Novice::DrawEllipse((int)bulletpos_.x, (int)bulletpos_.y, (int)playerradius_ / 2, (int)playerradius_ / 2, 0, BLACK, kFillModeSolid);
	bullet->Draw();
}

void Player::Bullet1() {
	if (isbullet_ == 1) {
		bulletpos_.y -= speed_ * 3;
	}if (bulletpos_.y <= -playerradius_) {
		isbullet_ = 0;
		bulletpos_.x = outer_.x;
		bulletpos_.y = outer_.y;
	}
}