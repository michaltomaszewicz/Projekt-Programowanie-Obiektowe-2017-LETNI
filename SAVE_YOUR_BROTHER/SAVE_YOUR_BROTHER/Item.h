#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class Player;
class Item
{
public:
	virtual void interact(Player & player) = 0;

	virtual void tobackpack(Player & player) = 0;

	virtual void sellitem(Player & player) = 0;


};

