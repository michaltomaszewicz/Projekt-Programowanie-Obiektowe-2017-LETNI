#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Item.h"

using namespace std;

class Item;
class Potion : public Item
{
protected:
	string name;
	int addzy;
	int val;

public:

	int potion_id;
	int order;

	struct Position
	{
		int x;
		int y;
	};

	Position potionposition;

	Potion();
	Potion(string, int, int, int, int, int);

	~Potion();

	int checkorder(Player &player);

	virtual void interact(Player & player);

	virtual void tobackpack(Player & player);

	virtual void sellitem(Player & player);


	friend class Player;
	friend void sklep(Player & player);
	friend void create_potion(ifstream &file, Potion & pot);
};

