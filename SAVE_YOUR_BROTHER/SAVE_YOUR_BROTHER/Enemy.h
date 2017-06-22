#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
//#include "Player.h //napotkany problem: w plikach nag³ówkowych powsta³ "cykl"(a nie powinien) - rozwi¹zane
#include <fstream>

using namespace std;

class Player;
class Enemy
{
public:
	struct Position
	{
		int x;
		int y;
	};

	Position eposition;

protected:
	int hp, gold, strength;
	string name;

public:

	Enemy() {};
	Enemy(string, int, int, int, int, int);

	~Enemy();

	void steal(Player & player);

	friend class Player;
	friend void home(Player & player);
	friend void create_enemy(ifstream & file, Enemy & enem);
};

