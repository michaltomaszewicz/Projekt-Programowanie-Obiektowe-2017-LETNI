#include "stdafx.h"
#include "Potion.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Item.h"
#include <vector>
#include <ctime>
#include "Player.h"

using namespace std;

Potion::Potion() {};

Potion tab1[];

Potion::Potion(string nazwa, int dodzdrowie, int wart, int wx, int wy, int id)
{
	name = nazwa;
	addzy = dodzdrowie;
	val = wart;
	potionposition.x = wx;
	potionposition.y = wy;
	potion_id = id;
}


Potion::~Potion()
{
}

int Potion::checkorder(Player &player)
{
	for (int i = 0; i < player.potions.size(); i++)
	{
		for (int j = 0; j <4; j++)///////////////////warunkiem jest ilosc wszystkich przedmiotow W OGOLE
		{
			if ((*player.potions[i]).potion_id == tab1[j].potion_id)
			{
				return i;
			}
		}
	}

}

void Potion::interact(Player & player)
{
	if (player.hp + addzy > player.maxhp)
	{
		player.hp = player.maxhp;
		player.beltspace += 1;
		cout << endl;
		cout << "Wypiles miksture: " << name << endl;
	}
	else
	{
		player.hp += addzy;
		player.beltspace += 1;
		cout << endl;
		cout << "Wypiles miksture: " << name << endl;
	}
	order = -1;

	for (int i = 0; i < player.potions.size(); i++)
	{
		(*player.potions[i]).order = checkorder(player);
	}
}

void Potion::tobackpack(Player & player)
{

	cout << endl;
	player.potions.push_back(this);
	player.mypotions.push_back(potion_id);
	cout << "Na pasek dodano przedmiot: " << name << endl;
	potionposition.x = -8; // na nasz pasek
	potionposition.y = -8; // na nasz pasek	
	player.beltspace -= 1;
	order = player.potions.size() - 1;
}

void Potion::sellitem(Player & player)
{
	checkorder(player);
	cout << endl;
	player.potions.erase(player.potions.begin() + order);
	player.mypotions.erase(player.mypotions.begin() + order);
	cout << "Sprzedano za " << val - 5 << " zlota" << endl;
	potionposition.x = -1; // do naszego ekwipunku
	potionposition.y = -1; // do naszego ekwipunku
						   //inbp = 0;
						   //inshop = 1;
	player.beltspace += 1;
	player.potsold++;
	player.gold += (val - 5);
	order = -1;

	for (int i = 0; i < player.potions.size(); i++)
	{
		(*player.potions[i]).order = checkorder(player);
	}
}