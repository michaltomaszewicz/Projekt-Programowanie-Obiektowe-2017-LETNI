#include "stdafx.h"
#include "Artifact.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Item.h"
#include <vector>
#include <ctime>
#include "Player.h"

using namespace std;

Artifact::Artifact() {};

Artifact tab[];

Artifact::Artifact(string nazwa, int dodhp, int dodsile, int dodspace, int dodpasek, int wartosc, int posx, int posy, int id, bool czywsklepie, bool czywbp)
{
	name = nazwa;
	addmaxhp = dodhp;
	addstrength = dodsile;
	addbspace = dodspace;
	addbelt = dodpasek;
	value = wartosc;
	artifactposition.x = posx;
	artifactposition.y = posy;
	item_id = id;
	inshop = czywsklepie;
	inbp = czywbp;
}


Artifact::~Artifact()
{
}

int Artifact::checkorder(Player &player)
{
	for (int i = 0; i < player.items.size(); i++)
	{
		for (int j = 0; j <4; j++)///////////////////warunkiem jest ilosc wszystkich przedmiotow W OGOLE
		{
			if ((*player.items[i]).item_id == tab[j].item_id)
			{
				return i;
			}
		}
	}

}

void Artifact::interact(Player & player)
{

}

void Artifact::tobackpack(Player & player)
{

	cout << endl;
	player.items.push_back(this);
	player.myitems.push_back(item_id);
	cout << "Do ekwipunku dodano przedmiot: " << name << endl;
	artifactposition.x = -9; // do naszego ekwipunku
	artifactposition.y = -9; // do naszego ekwipunku
	inbp = 1;
	inshop = 0;
	player.strengthfromitems += addstrength;
	player.maxhpfromitems += addmaxhp;
	player.bspacefromitems += addbspace;
	player.beltspacefromitems += addbelt;
	player.bspace -= 1;
	order = player.items.size() - 1;

}

void Artifact::sellitem(Player & player)
{
	checkorder(player);
	cout << endl;
	player.items.erase(player.items.begin() + order);//
	player.myitems.erase(player.myitems.begin() + order);//
	cout << "Sprzedano za " << value - 5 << " zlota" << endl;
	artifactposition.x = -1; // do naszego ekwipunku
	artifactposition.y = -1; // do naszego ekwipunku
	inbp = 0;
	inshop = 1;
	player.strengthfromitems -= addstrength;
	player.maxhpfromitems -= addmaxhp;
	player.bspacefromitems -= addbspace;
	player.beltspacefromitems -= addbelt;
	player.bspace += 1;
	player.artsold++;
	player.gold += (value - 5);
	order = -1;

	for (int i = 0; i < player.items.size(); i++)
	{
		(*player.items[i]).order = checkorder(player);
	}
}


