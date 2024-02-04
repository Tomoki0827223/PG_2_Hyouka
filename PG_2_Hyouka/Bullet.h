#pragma once
#include "Vector2.h"
class Bullet
{
public:

	Bullet();
	~Bullet();

	void Update();
	void Draw();

	Vector2 BulletPos_;
	float BulletRadius_;
	float BulletSpeed;
	bool isShot;
	float distance;

	Vector2 outer_;
	int isbullet_;

};

