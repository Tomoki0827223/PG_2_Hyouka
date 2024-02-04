#include "Enemy.h"


Enemy::Enemy() {
	enemypos_.x = 640.0f;
	enemypos_.y = 200.0f;
	enemyradius_ = 30.0f;
	speed_ = 3.0f;
	between_.x = 0;
	between_.y = 0;
	distance = 0;
	reborn = 0;
	isAlive = 1;
}

Enemy::~Enemy() {

}
void Enemy::Move() {
	if (isAlive == 1) {
		if (enemypos_.x <= 0.0f) {
			speed_ = 3.0f;
		}if (1280.0f <= enemypos_.x) {
			speed_ = -3.0f;
		}
		enemypos_.x += speed_;
	}
}
void Enemy::Draw() {
	if (isAlive == 1) {
		reborn = 0;
		Novice::DrawEllipse((int)enemypos_.x, (int)enemypos_.y, (int)enemyradius_, (int)enemyradius_, 0, RED, kFillModeSolid);
	}
}
void Enemy::Hit(Vector2 bullet1) {
	between_.x = (bullet1.x - enemypos_.x);
	between_.y = (bullet1.y - enemypos_.y);
	distance = sqrtf((between_.x) * (between_.x)) + sqrtf((between_.y) * (between_.y));
	if (distance <= playerradius_ + enemyradius_) {
		isbullet_ = 0;
		isAlive = 0;

	}
	if (isAlive == 0) {
		reborn++;
		if (reborn >= 120) {
			isAlive = 1;
		}
	}
}