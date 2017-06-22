#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Item.h"
#include <fstream>

using namespace std;

class Item;
class Artifact : public Item
{
protected:
	string name;
	int addmaxhp;
	int addstrength;
	int addbspace;
	int addbelt;
	int value;
	bool inshop;
	bool inbp;

public:

	int item_id;
	int order;

	struct Position
	{
		int x;
		int y;
	};

	Position artifactposition;

public:

	Artifact();
	Artifact(string, int, int, int, int, int, int, int, int, bool, bool); // nazwa +hp +strenght +bspace +pasekspace wartosc x y item_id inshop inbp
	~Artifact();

	int checkorder(Player &player);

	virtual void interact(Player & player);

	virtual void tobackpack(Player & player);

	virtual void sellitem(Player & player);

	friend class Player;
	friend void sklep(Player & player);
	friend void create_artifact(ifstream & file, Artifact & ar);
};

