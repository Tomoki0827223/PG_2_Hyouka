#pragma once
#include "Vector2.h"
#include<Novice.h>
#include"Player.h"
#include <corecrt_math.h>
class Enemy :public Player
{
private:
public:
	Vector2 enemypos_;
	Vector2 between_;
	float enemyradius_;
	float speed_;
	float distance;
	static int isAlive;
	int reborn;
	Enemy();
	~Enemy();
	
	void Move();
	void Draw();
	void Hit(Vector2 bullet);

	
};

