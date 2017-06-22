#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Enemy.h"
#include <fstream>
#include "Artifact.h"
#include "Item.h"
#include <vector>
#include <ctime>
#include "Potion.h"

using namespace std;

//Artifact tab[1];/////////////////lista artefaktow W OGOLE

class Enemy;
class Player : public Enemy
{
protected:
	int maxhp;

	int strengthfromitems = 0;
	int maxhpfromitems = 0;
	int bspacefromitems = 0;
	int beltspacefromitems = 0;
	int energy = 100;

public:
	int bspace;
	int beltspace;
	int artsold = 0;//ilosc sprzedane przedmioty
	int potsold = 0;//potiony

	char prepos = 'o';

	vector <Artifact*> items;// wektor adresów
	vector <int> myitems;// wektor numerow id przedmiotów w moim ekwipunku

	vector <Potion*> potions;
	vector <int> mypotions;

	Player(string, int, int, int, int, int, int, int, int);//nazwa maxzycie zycie zloto sila x y bspace pasek
	~Player();

	int sumstrenght();
	int sumbspace();
	int sumbeltspace();
	int summaxhp();

	void introduce();

	void myArtifacts();

	void myPotions();

	void drinkPotion();

	void sleeep(Enemy tab2[]);

	int wincondition();
	bool czyzyje();

	int calkowitygold();

	friend class Artifact;
	friend class Potion;
	friend class Enemy;
	friend void sklep(Player & player);
	friend void home(Player & player);
};

