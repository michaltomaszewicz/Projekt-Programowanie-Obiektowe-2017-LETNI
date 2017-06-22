#include "stdafx.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Player.h"
#include <fstream>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//Enemy::Enemy() {};
Enemy tab2[];

Enemy::Enemy(string nazwa, int zycie, int zloto, int sila, int x, int y)
{
	name = nazwa;
	hp = zycie;
	gold = zloto;
	strength = sila;
	eposition.x = x;
	eposition.y = y;
}

Enemy::~Enemy()
{
}

void Enemy::steal(Player & player)
{

	for (int i = 0; i < 6; i++)////////////warunkiem liczba wszystkich wrogow
	{
		if ((*this).name == tab2[i].name)
		{
			if (player.gold < 10)
			{
				cout << "Nie masz wystarczajaaco duzo zlota aby sie pojedynkowac" << endl;
			}
			else
			{
				if (player.energy < 30)
				{
					cout << endl;
					cout << "Nie mozesz pojedynkowac sie z tym przeciwnikiem, jestes zbyt zmeczony. Energia: " << player.energy << "/100" << endl;
					cout << "Wroc do domu, aby odpoczac." << endl;
				}
				else
				{
					if (tab2[i].gold == 0)
					{
						cout << endl;
						cout << "Przeciwnik jest splukany, nie chce moze z Toba walczyc." << endl;
					}
					else
					{ //////////walka
						int rounds;
						int liczba1;
						int liczba2;
						int wynik;
						int mojwynik;
						int won = 0;
						cout << endl;
						cout << "-----WALKA-----" << endl;
						cout << endl;


						if (tab2[i].strength - player.strength <= 0)
						{
							rounds = 1;
						}
						else
						{
							rounds = tab2[i].strength - player.strength;
						}
						cout << "Ilosc rund: " << rounds << endl;

						cout << "Podawaj wyniki!" << endl;
						cout << "Zatwierdzaj  ENTERem" << endl;

						for (int j = 0; j < rounds; j++)
						{
							srand(time(NULL));
							liczba1 = rand() % 10 + 1;
							liczba2 = rand() % 5 + 1;
							wynik = liczba1 * liczba2;

							cout << endl;
							cout << liczba1 << " x " << liczba2 << " = ";
							cin >> mojwynik;

							if (wynik == mojwynik)
							{
								won++;
							}
						}

						if (won == rounds)
						{
							cout << endl;
							cout << "Pokonales " << tab2[i].name << ", otrzymujesz wygrana w wysokosci: " << tab2[i].gold << " zlota" << endl;
							player.gold += tab2[i].gold;
							tab2[i].gold = 0;
							player.energy -= 30;
							cout << "Twoja energia: " << player.energy << "/100" << endl;
						}
						else
						{
							cout << endl;
							cout << "Zostales pokonany. Tracisz 10 zlota" << endl;
							player.gold -= 10;
							player.energy -= 30;
							cout << "Twoja energia: " << player.energy << "/100" << endl;
							Sleep(5000);
						}

					}

				}
			}
		}
	}




}
