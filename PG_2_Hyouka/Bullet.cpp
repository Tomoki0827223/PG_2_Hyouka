#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet()
{
	BulletPos_.x = 300;
	BulletPos_.y = 300;
	BulletRadius_ = 30;
	BulletSpeed = 15;
	distance = 0;
	isbullet_ = 0;
	outer_.x = 50;
	outer_.y = 50;
	isShot = false;

}

Bullet::~Bullet()
{
}

void Bullet::Update()
{

	if (isShot == true) {
		BulletPos_.y -= BulletSpeed;
		if (BulletPos_.y < 0) { isShot = false; }
	}

}

void Bullet::Draw()
{
	if (isShot == true) { Novice::DrawEllipse((int)BulletPos_.x, (int)BulletPos_.y, (int)BulletRadius_, (int)BulletRadius_, 0.0f, WHITE, kFillModeSolid); }
}

