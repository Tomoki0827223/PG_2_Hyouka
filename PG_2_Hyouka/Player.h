#pragma once
#include"Vector2.h"
#include "Bullet.h"
#include<Novice.h>
#include <math.h>

class Player
{
public:
	//player
	Vector2 playerpos_;
	Vector2 bulletpos_;
	Vector2 outer_;
	float playerradius_;
	float speed_;
	int isbullet_;

	Vector2 between_;
	float distance2;
	int isAlive2;
	int reborn2;

public:

	Bullet* bullet;

	Player();
	~Player();
	void PlayerMove(char* keys,char *preKeys);
	void Hit(Vector2 player, Vector2 enemy);
	void PlayerDraw();
	void Bullet1();
	
};

