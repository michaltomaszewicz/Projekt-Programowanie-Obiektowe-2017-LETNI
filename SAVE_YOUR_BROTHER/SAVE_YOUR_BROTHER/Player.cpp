#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Enemy.h"
#include <fstream>
#include <vector>
#include <conio.h>
#include <ctime>

using namespace std;


Artifact tab[];
Potion tab1[];
Enemy tab2[];

Player::Player(string nazwa, int maxzycie, int zycie, int zloto, int sila, int x, int y, int pojemnosc, int pasek)
{
	name = nazwa;
	hp = zycie;
	gold = zloto;
	strength = sila;
	eposition.x = x;
	eposition.y = y;
	maxhp = maxzycie;
	bspace = pojemnosc;
	beltspace = pasek;
}


Player::~Player()
{
}

int Player::sumstrenght()
{
	return strength + strengthfromitems;
}

int Player::sumbspace()
{
	return bspace += bspacefromitems;
}

int Player::sumbeltspace()
{
	return beltspace += beltspacefromitems;
}

int Player::summaxhp()
{
	return maxhp += maxhpfromitems;
}



void Player::introduce()
{
	cout << endl;
	cout << "-----STSTYSTYKI GRACZA-----" << endl;
	cout << "Moje zloto: " << gold << endl;
	cout << "Zycie: " << hp << "/" << summaxhp() << endl;
	cout << "Energia: " << energy << "/100" << endl;
	cout << "Moja sila: " << sumstrenght() << endl;
	cout << "Wolne miejsce w plecaku: " << sumbspace() << endl;
	cout << "Wolne miejsce na pasku: " << sumbeltspace() << endl;
}

void Player::myArtifacts()
{
	cout << endl;

	cout << "-----MOJE PRZEDMIOTY-----" << endl;
	//cout << myitems.size();

	int size = myitems.size();////

	if (size == 0)
	{
		cout << endl;
		cout << "Nie posiadasz zadnych przedmiotow." << endl;
	}
	else
	{

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 6; j++)// warunkiem bêdzie ilosc artekfaktow W OgOLE
			{
				if (myitems[i] == tab[j].item_id)
				{
					cout << endl;
					cout << "- " << tab[j].name << endl;
					cout << "	+ " << tab[j].addmaxhp << " maksymalnego zycia" << endl;
					cout << "	+ " << tab[j].addstrength << " sily" << endl;
					cout << "	+ " << tab[j].addbspace << " miejsca w ekwipunku" << endl;
					cout << "	+ " << tab[j].addbelt << " miejsca na pasku z miksturami" << endl;
					cout << "	wartosc: " << tab[j].value << " zlota" << endl;


				}
			}

		}
	}


}

void Player::myPotions()
{
	cout << endl;

	cout << "-----MOJE ELIKSIRY-----" << endl;

	int size = potions.size();

	if (size == 0)
	{
		cout << endl;
		cout << "Nie posiadasz zadnych eliksirow." << endl;
	}
	else
	{

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 5; j++)// warunkiem bêdzie ilosc potionow W OgOLE
			{
				if (mypotions[i] == tab1[j].potion_id)
				{
					cout << endl;
					cout << "- " << tab1[j].name << endl;
					cout << "	+" << tab1[j].addzy << " punktow zycia" << endl;
					cout << "	wartosc: " << tab1[j].val << " zlota" << endl;
				}
			}

		}
	}
}

int Player::wincondition()
{
	if (Player::gold >= 200)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Player::drinkPotion()
{
	if (potions.size() > 0)
	{
		//Potion a, b, c, d, e, f, g, h, i, j;
		Potion p;

		cout << endl;
		cout << "-----MOJE POTIONY-----" << endl;
		for (int i = 0; i < potions.size(); i++)
		{
			p = *potions[i];
			cout << i << " - wypij " << p.name << endl;
		}
		cout << "<dowlony klawisz> -  aby nie pic" << endl;


		unsigned char z = _getch();

		if (z == '0')
		{
			(*potions[0]).interact(*(this));
			potions.erase(potions.begin() + (int)(z - 48));
			mypotions.erase(mypotions.begin() + (int)(z - 48));
		}
		else if (z == '1')
		{
			if (potions.size() >1)
			{
				(*potions[1]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}

		}
		else if (z == '2')
		{
			if (potions.size() > 2)
			{
				(*potions[2]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}

		}
		else if (z == '3')
		{

			if (potions.size() > 3)
			{
				(*potions[3]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}

		}
		else if (z == '4')
		{
			if (potions.size() > 4)
			{
				(*potions[4]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}
		}
		else if (z == '5')
		{
			if (potions.size() > 5)
			{
				(*potions[5]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}
		}
		else if (z == '6')
		{
			if (potions.size() > 6)
			{
				(*potions[6]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}
		}
		else if (z == '7')
		{
			if (potions.size() > 7)
			{
				(*potions[7]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}
		}
		else if (z == '8')
		{
			if (potions.size() > 8)
			{
				(*potions[8]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}
		}
		else if (z == '9')
		{
			if (potions.size() > 9)
			{
				(*potions[9]).interact(*(this));
				potions.erase(potions.begin() + (int)(z - 48));
				mypotions.erase(mypotions.begin() + (int)(z - 48));
			}
		}

	}
	else
	{
		cout << endl;
		cout << "Nie masz zadnych potionow do wypicia" << endl;
	}
}

void Player::sleeep(Enemy tab2[])
{
	energy = 100;

	for (int i = 0; i < 6; i++)//warunkiem jest ilosc wrogow w OGOLE
	{
		tab2[i].gold += 10;
	}
	cout << tab2[0].gold << endl;
}

bool Player::czyzyje()
{
	if (hp <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Player::calkowitygold()
{
	int goldfromitems = 0;
	int goldfrompotions = 0;

	for (int i = 0; i < items.size(); i++)
	{
		goldfromitems += (*items[i]).value;
	}

	for (int j = 0; j < items.size(); j++)
	{
		goldfrompotions += (*potions[j]).val;
	}

	return gold + goldfromitems + goldfrompotions;
}

