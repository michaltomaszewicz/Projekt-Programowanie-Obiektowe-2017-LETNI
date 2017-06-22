// SAVE_YOUR_BROTHER.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include <vector>
#include <ctime>
#include "Artifact.h"
#include "Potion.h"


using namespace std;

struct Position
{
	int x;
	int y;
};

Artifact tab[6];///////////////////////////////////////////////////tablica artefaktow

Potion tab1[5];/////////////////////////////////////////////tablica potionow

Enemy tab2[6];//////////////// tablica przeciwnikow


int rozmiar = 10;

char ** mapa = new char *[rozmiar];

class Player;
void sklep(Player & player);// predefinicja sklepu
void home(Player & player); // predefinicja domu

void create_artifact(ifstream & file, Artifact & ar)
{
	file >> ar.name;
	file >> ar.addmaxhp;
	file >> ar.addstrength;
	file >> ar.addbspace;
	file >> ar.addbelt;
	file >> ar.value;
	file >> ar.artifactposition.x;
	file >> ar.artifactposition.y;
	file >> ar.item_id;
	file >> ar.inshop;
	file >> ar.inbp;
}

void create_potion(ifstream & file, Potion & pot)
{
	file >> pot.name;
	file >> pot.addzy;
	file >> pot.val;
	file >> pot.potionposition.x;
	file >> pot.potionposition.y;
	file >> pot.potion_id;
}

void create_enemy(ifstream & file, Enemy & enem)
{
	file >> enem.name;
	file >> enem.hp;
	file >> enem.gold;
	file >> enem.strength;
	file >> enem.eposition.x;
	file >> enem.eposition.y;
}

int main()
{
	ifstream plik;
	plik.open("mapa.txt");

	for (int i = 0; i < rozmiar; i++) // dynamiczna tablica typu char jako mapa
	{
		mapa[i] = new char[rozmiar];
	}

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			plik >> mapa[i][j];
		}
	}
	plik.close(); //koniec pracy z plikiem


	int ilosc;
	plik.open("artifacts.txt");////////////////////////////////////////////wczytujemy artefakty z pliku
	plik >> ilosc;

	for (int i = 0; i < ilosc; i++)
	{
		create_artifact(plik, tab[i]);
	}

	plik.close();

	int il;
	plik.open("potions.txt");///////////////////////////////////////////////////wczytujemy potiony z pliku
	plik >> il;

	for (int i = 0; i < il; i++)
	{
		create_potion(plik, tab1[i]);
	}
	plik.close();

	int ilo;
	plik.open("enemies.txt");
	plik >> ilo;
	for (int i = 0; i < ilo; i++)
	{
		create_enemy(plik, tab2[i]);
	}


	cout << "		 psss.  d s.    d    b  Ssssss              Ss   sS    sSSSs    d       b  d ss.   " << endl;
	cout << "		d       S   O   S    S  S                     S S     S     S   S       S  S    b  " << endl;
	cout << "		Y       S    b  S    S  S                      S     S       S  S       S  S    P  " << endl;
	cout << "		 Sss.   SssSSO  S    S  Ssssss                 S     S       S  S       S  S sS'   " << endl;
	cout << "		     b  S    O  S    S  S                      S     S       S  S       S  S   S   " << endl;
	cout << "		     P  S    O   S   S  S                      S      S     S    S     S   S    S  " << endl;
	cout << "		`Sss'   P    P    ""SS    PssSSs                 P       ""sssss""      ""sssss""    P    P  " << endl;
	cout << "		                                                                                   " << endl;
	cout << "		           ssssp   dsss.     sSSSs   sssssssss  S    S   Ssssss   sddss.           " << endl;
	cout << "		           S    b  S    b   S     S      S      S    S   S        S    b           " << endl;
	cout << "		           S    P  S    P  S       S     S      S    S   S        S    P           " << endl;
	cout << "		           SSSSS'  SSsS'   S       S     S      SSSSSS   Ssssss   S sS'            " << endl;
	cout << "		           S    b  S   S   S       S     S      S    S   S        S   S            " << endl;
	cout << "		           S    P  S    S   S     S      S      S    S   S        S    S           " << endl;
	cout << "		           PSSSP   P    P    ""ssss""        S      P    P   PssSSs   P    P           " << endl;



	Sleep(5000);
	cout << endl;
	cout << "				   nacisnij <dowolny klawisz> aby kontynuowac" << endl;

	char a11 = _getch();
	switch (a11)
	{
	default:
		system("cls");
		break;
	}

	cout << "Twojemu bratu grozi niebespieczenstwo!" << endl;
	cout << "Porwali go zli ludzie i zadaja okupu." << endl;
	cout << "Cena za brata wynosi 200 zlota" << endl;
	cout << "Twoim zadaniem bedzie uzbierac zadana sume i wplacic okup za brata" << endl;
	Sleep(3000);

	cout << endl;
	cout << "nacisnij <dowolny klawisz> aby kontynuowac" << endl;



	char a10 = _getch();
	switch (a10)
	{
	default:
		system("cls");
		break;
	}

	cout << "-----INSTRUKCJA-----" << endl;
	cout << endl;

	cout << "Znajdujesz sie na pozycji X" << endl;
	cout << "Litera W oznacza lokalizacje porywaczy, wlasnie tam musisz wplacic okup (200 zlota)" << endl;
	cout << "Nie mozesz poruszac sie poza mape ORAZ po znakach '_'" << endl;
	cout << "Litera P oznaczona jest mikstura, ktora mozesz podniesc, a nastepnie wypic" << endl;
	cout << "Po podniesieniu mikstury laduje ona na Twoim pasku" << endl;
	cout << "Litera I oznaczony jest przedmiot, ktory moze zwiekszyc Twoje statystyki" << endl;
	cout << "Po podniesieniu przedmioty laduja w Towim plecaku" << endl;
	cout << "Litera H oznaczony jest Twoj dom. mozesz w nim odpoczac" << endl;
	cout << "Litera E oznaczeni sa wrogowie. Posiadaja oni swoje zloto. Mozesz sie z nimi" << endl;
	cout << "pojedynkowac o zloto, ktore przyda Ci sie do oplacenia okupu." << endl;
	cout << "Aby walczyc musisz posiadac conajmniej 10 zlota. Jesli przegrasz to tracisz 10 zlota." << endl;
	cout << "Kazdy pojedynek jest dosc wyczerpujacy. Tracisz w nich energie. Gdy Twoja energia osiagnie niskipoziom" << endl;
	cout << "nie bedziesz juz mogl brac udzialu w pojedynkach. Nalezy wtedy udac sie do domu i zaczerpnac odpoczynku" << endl;
	cout << "Litera S oznaczony jest sklep. Za zlotomozesz tam kupowac oraz sprzedawac posiadane przedmioty oraz mikstury" << endl;
	cout << endl;
	cout << "Gdy Twoje punkty zycia spadna do 0 to przegrywasz." << endl;
	cout << "Gdy suma wartosci Twoich przedmiotw, wartosci potionow i ilosci posiadanego zlota" << endl;
	cout << "bedzie mniejsza niz 10 to przegrywasz" << endl;
	cout << "Poruszasz sie za pomoca strzalek" << endl;
	cout << "Aby zakonczyc gre nacisnij Esc" << endl;
	cout << endl;
	cout << "Oto Twoja mapa!" << endl;// wypisywanie mapy

	cout << endl;

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			cout << mapa[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "nacisnij <dowolny klawisz> aby kontynuowac" << endl;

	char a12 = _getch();
	switch (a12)
	{
	default:
		system("cls");
		break;
	}


	system("cls");


	///////////////////////////////////////////////////////////////////
	char a13;

	Position me;
	Position end;
	Position eloss;

	Position shop;
	Position hom;

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (mapa[i][j] == 'X')// znajduje moja pozycje na mapie
			{
				me.x = j;
				me.y = i;
			}

			if (mapa[i][j] == 'W')// znajduje pozycje wygranej
			{
				end.x = j;
				end.y = i;
			}

			if (mapa[i][j] == 'L')// znajduje pozycje przegranej
			{
				eloss.x = j;
				eloss.y = i;
			}

			if (mapa[i][j] == 'S')// znajduje pozycje sklepu
			{
				shop.x = j;
				shop.y = i;
			}

			if (mapa[i][j] == 'H')// znajduje pozycje domu
			{
				hom.x = j;
				hom.y = i;
			}

		}
	}

	///////////////////////////////////////////////////////////////////////// klasy

	Player ja("Michal", 100, 80, 10, 1, me.x, me.y, 4, 2); // miejsce w plecaku, miejsce na pasku

														   /////////////////////////////////////////////////////////////////////		
	cout << "Moja pozycja to ";
	cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			cout << mapa[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "ENTER - aby otrzymac pomoc" << endl;
	cout << "s - aby wyswietlic informacje o graczu" << endl;
	cout << "d - aby wypic miksture." << endl;
	bool winnn = 0;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (winnn == 0) //petla
	{
		unsigned char znak = _getch();

		system("cls");

		switch (znak)
		{

		case 72: //strza³ka w górê
			if ((ja.eposition.y - 1 >= 0) && (mapa[ja.eposition.y - 1][ja.eposition.x] != '_'))
			{
				//problemy ze wspolrzednymi: rozwiazany
				if (mapa[ja.eposition.y - 1][ja.eposition.x] != 'I' && mapa[ja.eposition.y - 1][ja.eposition.x] != 'P')
				{

					mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
					ja.prepos = mapa[ja.eposition.y - 1][ja.eposition.x];
					mapa[ja.eposition.y - 1][ja.eposition.x] = 'X';
					ja.eposition.y -= 1;
				}
				else
				{
					if (ja.sumbspace() > 0 && mapa[ja.eposition.y - 1][ja.eposition.x] == 'I')
					{
						mapa[ja.eposition.y][ja.eposition.x] = 'o';
						mapa[ja.eposition.y - 1][ja.eposition.x] = 'X';
						ja.eposition.y -= 1;
					}
					else
					{
						if (ja.sumbeltspace() >0 && mapa[ja.eposition.y - 1][ja.eposition.x] == 'P')
						{
							mapa[ja.eposition.y][ja.eposition.x] = 'o';
							mapa[ja.eposition.y - 1][ja.eposition.x] = 'X';
							ja.eposition.y -= 1;
						}
						else
						{
							mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
							ja.prepos = mapa[ja.eposition.y - 1][ja.eposition.x];
							mapa[ja.eposition.y - 1][ja.eposition.x] = 'X';
							ja.eposition.y -= 1;
						}

					}

				}

				if (ja.eposition.x == shop.x && ja.eposition.y == shop.y)/////////////////////////////////////czy w sklepie
				{
					sklep(ja);
				}

				if (ja.eposition.x == hom.x && ja.eposition.y == hom.y)/////////////////////////////////////czy w domu
				{
					home(ja);
				}

				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic informacje o graczu" << endl;
				cout << "d - aby wypic miksture." << endl;

			}
			else
			{
				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}

				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic informacje o graczu" << endl; cout << endl;
				cout << "d - aby wypic miksture." << endl;
				cout << "Nie mozesz tam pojsc!" << endl;
			}
			break;

		case 80: //strza³ka w dó³
			if (ja.eposition.y + 1 < rozmiar && (mapa[ja.eposition.y + 1][ja.eposition.x] != '_'))
			{
				if (mapa[ja.eposition.y + 1][ja.eposition.x] != 'I' && mapa[ja.eposition.y + 1][ja.eposition.x] != 'P')
				{
					mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
					ja.prepos = mapa[ja.eposition.y + 1][ja.eposition.x];
					mapa[ja.eposition.y + 1][ja.eposition.x] = 'X';
					ja.eposition.y += 1;
				}
				else
				{
					if (ja.sumbspace() > 0 && mapa[ja.eposition.y + 1][ja.eposition.x] == 'I')
					{
						mapa[ja.eposition.y][ja.eposition.x] = 'o';
						mapa[ja.eposition.y + 1][ja.eposition.x] = 'X';
						ja.eposition.y += 1;
					}
					else
					{
						if (ja.sumbeltspace() >0 && mapa[ja.eposition.y + 1][ja.eposition.x] == 'P')
						{
							mapa[ja.eposition.y][ja.eposition.x] = 'o';
							mapa[ja.eposition.y + 1][ja.eposition.x] = 'X';
							ja.eposition.y += 1;
						}
						else
						{
							mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
							ja.prepos = mapa[ja.eposition.y + 1][ja.eposition.x];
							mapa[ja.eposition.y + 1][ja.eposition.x] = 'X';
							ja.eposition.y += 1;
						}

					}
				}

				if (ja.eposition.x == shop.x && ja.eposition.y == shop.y)/////////////////////////////////////czy w sklepie
				{
					sklep(ja);
				}
				if (ja.eposition.x == hom.x && ja.eposition.y == hom.y)/////////////////////////////////////czy w domu
				{
					home(ja);
				}

				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic informacje o graczu" << endl;
				cout << "d - aby wypic miksture." << endl;

			}
			else
			{
				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}

				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic informacje o graczu" << endl;
				cout << "d - aby wypic miksture." << endl;
				cout << endl;
				cout << "Nie mozesztam pojsc!" << endl;
			}
			break;

		case 75: //strza³ka w lewo
			if ((ja.eposition.x - 1 >= 0) && (mapa[ja.eposition.y][ja.eposition.x - 1] != '_'))
			{
				if (mapa[ja.eposition.y][ja.eposition.x - 1] != 'I' && mapa[ja.eposition.y][ja.eposition.x - 1] != 'P')
				{
					mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
					ja.prepos = mapa[ja.eposition.y][ja.eposition.x - 1];
					mapa[ja.eposition.y][ja.eposition.x - 1] = 'X';
					ja.eposition.x -= 1;
				}
				else
				{
					if (ja.sumbspace() > 0 && mapa[ja.eposition.y][ja.eposition.x - 1] == 'I')
					{
						mapa[ja.eposition.y][ja.eposition.x] = 'o';
						mapa[ja.eposition.y][ja.eposition.x - 1] = 'X';
						ja.eposition.x -= 1;
					}
					else
					{
						if (ja.sumbeltspace() > 0 && mapa[ja.eposition.y][ja.eposition.x - 1] == 'P')
						{
							mapa[ja.eposition.y][ja.eposition.x] = 'o';
							mapa[ja.eposition.y][ja.eposition.x - 1] = 'X';
							ja.eposition.x -= 1;
						}
						else
						{
							mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
							ja.prepos = mapa[ja.eposition.y][ja.eposition.x - 1];
							mapa[ja.eposition.y][ja.eposition.x - 1] = 'X';
							ja.eposition.x -= 1;
						}

					}

				}

				if (ja.eposition.x == shop.x && ja.eposition.y == shop.y)/////////////////////////////////////czy w sklepie
				{
					sklep(ja);
				}
				if (ja.eposition.x == hom.x && ja.eposition.y == hom.y)/////////////////////////////////////czy w domu
				{
					home(ja);
				}



				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic statystyki" << endl;
				cout << "d - aby wypic miksture." << endl;

			}
			else
			{
				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}

				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic informacje o graczu" << endl;
				cout << "d - aby wypic miksture." << endl;
				cout << endl;
				cout << "Nie mozesz tam pojsc!" << endl;
			}
			break;

		case 77: //strza³ka w prawo
			if ((ja.eposition.x + 1 <rozmiar) && (mapa[ja.eposition.y][ja.eposition.x + 1] != '_'))
			{
				if (mapa[ja.eposition.y][ja.eposition.x + 1] != 'I' && mapa[ja.eposition.y][ja.eposition.x + 1] != 'P')
				{
					mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
					ja.prepos = mapa[ja.eposition.y][ja.eposition.x + 1];
					mapa[ja.eposition.y][ja.eposition.x + 1] = 'X';
					ja.eposition.x += 1;
				}
				else
				{
					if (ja.sumbspace() > 0 && mapa[ja.eposition.y][ja.eposition.x + 1] == 'I')
					{
						mapa[ja.eposition.y][ja.eposition.x] = 'o';
						mapa[ja.eposition.y][ja.eposition.x + 1] = 'X';
						ja.eposition.x += 1;
					}
					else
					{
						if (ja.sumbeltspace() > 0 && mapa[ja.eposition.y][ja.eposition.x + 1] == 'P')
						{
							mapa[ja.eposition.y][ja.eposition.x] = 'o';
							mapa[ja.eposition.y][ja.eposition.x + 1] = 'X';
							ja.eposition.x += 1;
						}
						else
						{
							mapa[ja.eposition.y][ja.eposition.x] = ja.prepos;
							ja.prepos = mapa[ja.eposition.y][ja.eposition.x + 1];
							mapa[ja.eposition.y][ja.eposition.x + 1] = 'X';
							ja.eposition.x += 1;
						}
					}
				}

				if (ja.eposition.x == shop.x && ja.eposition.y == shop.y)/////////////////////////////////////czy w sklepie
				{
					sklep(ja);

				}
				if (ja.eposition.x == hom.x && ja.eposition.y == hom.y)/////////////////////////////////////czy w domu
				{
					home(ja);
				}



				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic statystyki" << endl;
				cout << "d - aby wypic miksture." << endl;

			}
			else
			{
				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}

				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic statystyki" << endl;
				cout << "d - aby wypic miksture." << endl;
				cout << endl;
				cout << "Nie mozesz tam pojsc!" << endl;
			}
			break;

		case 13:
			system("cls");
			for (int i = 0; i < rozmiar; i++)
			{
				for (int j = 0; j < rozmiar; j++)
				{
					cout << mapa[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "Znajdujesz sie na pozycji X" << endl;
			cout << "Litera W oznacza lokalizacje porywaczy, wlasnie tam musisz wplacic okup (200 zlota)" << endl;
			cout << "Nie mozesz poruszac sie poza mape ORAZ po znakach '_'" << endl;
			cout << "Litera P oznaczona jest mikstura, ktora mozesz podniesc, a nastepnie wypic" << endl;
			cout << "Po podniesieniu mikstury laduje ona na Twoim pasku" << endl;
			cout << "Litera I oznaczony jest przedmiot, ktory moze zwiekszyc Twoje statystyki" << endl;
			cout << "Po podniesieniu przedmioty laduja w Towim plecaku" << endl;
			cout << "Litera H oznaczony jest Twoj dom. mozesz w nim odpoczac" << endl;
			cout << "Litera E oznaczeni sa wrogowie. Posiadaja oni swoje zloto. Mozesz sie z nimi" << endl;
			cout << "pojedynkowac o zloto, ktore przyda Ci sie do oplacenia okupu." << endl;
			cout << "Aby walczyc musisz posiadac conajmniej 10 zlota. Jesli przegrasz to tracisz 10 zlota." << endl;
			cout << "Kazdy pojedynek jest dosc wyczerpujacy. Tracisz w nich energie. Gdy Twoja energia osiagnie niskipoziom" << endl;
			cout << "nie bedziesz juz mogl brac udzialu w pojedynkach. Nalezy wtedy udac sie do domu i zaczerpnac odpoczynku" << endl;
			cout << "Litera S oznaczony jest sklep. Za zlotomozesz tam kupowac oraz sprzedawac posiadane przedmioty oraz mikstury" << endl;
			cout << endl;
			cout << "Gdy Twoje punkty zycia spadna do 0 to przegrywasz." << endl;
			cout << "Gdy suma wartosci Twoich przedmiotw, wartosci potionow i ilosci posiadanego zlota" << endl;
			cout << "bedzie mniejsza niz 10 to przegrywasz" << endl;
			cout << "Poruszasz sie za pomoca strzalek" << endl;
			cout << "Aby zakonczyc gre nacisnij Esc" << endl;

			Sleep(2000);

			cout << endl;
			cout << "nacisnij <dowolny klawisz> aby kontynuowac" << endl;

			a13 = _getch();
			switch (a13)
			{
			default:
				system("cls");

				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic statystyki" << endl;
				cout << "d - aby wypic miksture." << endl;

				break;
			}
			break;

		case 27:

			char decision;
			system("cls");
			cout << "Czy na pewno chcesz zakonczyc gre?" << endl;
			cout << "t - tak, chce wyjsc z programu" << endl;
			cout << "<dowolny przycisk> -aby wrocic do gry" << endl;
			decision = _getch();

			switch (decision)
			{

			case 't':
				system("cls");
				system("Pause");
				return 0;
				break;

			default:
				system("cls");
				cout << "Moja pozycja to ";
				cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
				for (int i = 0; i < rozmiar; i++)
				{
					for (int j = 0; j < rozmiar; j++)
					{
						cout << mapa[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				cout << "ENTER - aby otrzymac pomoc" << endl;
				cout << "s - aby wyswietlic statystyki" << endl;
				cout << "d - aby wypic miksture." << endl;
				break;
			}

			break;

		case 's':

			system("cls");
			cout << "Moja pozycja to ";
			cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
			for (int i = 0; i < rozmiar; i++)
			{
				for (int j = 0; j < rozmiar; j++)
				{
					cout << mapa[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "ENTER - aby otrzymac pomoc" << endl;
			cout << "s - aby wyswietlic statystyki" << endl;
			cout << "d - aby wypic miksture." << endl;
			ja.introduce();
			ja.myArtifacts();
			ja.myPotions();
			break;

		case 'd':

			system("cls");
			cout << "Moja pozycja to ";
			cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
			for (int i = 0; i < rozmiar; i++)
			{
				for (int j = 0; j < rozmiar; j++)
				{
					cout << mapa[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "ENTER - aby otrzymac pomoc" << endl;
			cout << "s - aby wyswietlic statystyki" << endl;
			cout << "d - aby wypic miksture." << endl;

			ja.drinkPotion();

			break;

		default:
			cout << "Moja pozycja to ";
			cout << "[" << ja.eposition.x << ", " << ja.eposition.y << "]" << endl;
			for (int i = 0; i < rozmiar; i++)
			{
				for (int j = 0; j < rozmiar; j++)
				{
					cout << mapa[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "ENTER - aby otrzymac pomoc" << endl;
			cout << "s - aby wyswietlic statystyki" << endl;
			cout << "d - aby wypic miksture." << endl;

			break;
		}
		//////////////////////// interakcja z przeciwnikiem

		for (int i = 0; i < ilo; i++)
		{
			if (ja.eposition.x == tab2[i].eposition.x && ja.eposition.y == tab2[i].eposition.y)
			{
				tab2[i].steal(ja);
			}
		}

		////////////////////////interakcja z przedmiotem/////////////////////////////////////////////////////szukaæ w tablicy

		for (int i = 0; i < ilosc; i++)
		{
			if (ja.eposition.x == tab[i].artifactposition.x && ja.eposition.y == tab[i].artifactposition.y)
			{
				if (ja.sumbspace() > 0)
				{
					tab[i].tobackpack(ja);
				}
				else
				{
					cout << endl;
					cout << "Nie mozesz podniesc tego przedmiotu. Brak miejsca w ekwipunku." << endl;
				}
			}
		}


		/////////////////////////interakcja z potionem

		for (int i = 0; i < il; i++)
		{
			if (ja.eposition.x == tab1[i].potionposition.x && ja.eposition.y == tab1[i].potionposition.y)
			{
				if (ja.sumbeltspace() > 0)
				{
					tab1[i].tobackpack(ja);
				}
				else
				{
					cout << endl;
					cout << "Nie mozesz podniesc tego eliiksiru. Brak miejsca na pasku" << endl;
				}
			}
		}

		if ((ja.eposition.x == end.x) && (ja.eposition.y == end.y))
		{
			if (ja.wincondition() == 1)
			{
				winnn = 1;
			}
			else
			{
				cout << endl;
				cout << "-Nie masz zlota? A juz mi stad zmykaj!" << endl;
			}

		}

		if (ja.czyzyje() == 0)
		{
			system("cls");
			cout << "Przegrales" << endl;
			system("pause");
			return 0;
		}

		if (ja.calkowitygold() < 10)
		{
			system("cls");
			cout << "Przegrales" << endl;
			system("pause");
			return 0;
		}


	}

	cout << "Twoj brat jest wolny" << endl;
	Sleep(3000);
	system("cls");
	cout << "Brawo udalo Ci sie ukonczyc gre!" << endl;

	for (int i = 0; i < rozmiar; i++)
	{
		delete[] mapa[i];
	}

	delete[] mapa;

	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sklep(Player & player)
{
	bool exit = 0;
	while (exit == 0) {

		cout << endl;

		cout << "Zloto: " << player.gold << endl;
		cout << "-----SKLEP-----" << endl;
		cout << "	a - aby sprzedac przedmioty" << endl;
		cout << "	b - aby kupic przedmioty" << endl;
		cout << "<dowlony klawisz> - aby wyjsc ze sklepu" << endl;

		unsigned char znak1 = _getch();
		unsigned char znak2;
		unsigned char znak3;

		//int suma = (player.myitems.size() + player.mypotions.size());

		switch (znak1)
		{
		case 'a':

			system("cls");
			cout << "Zloto: " << player.gold << endl;
			cout << endl;


			cout << "Przedmioty:" << endl;
			if (player.items.size() == 0)
			{
				cout << "Brak przedmiotow" << endl;
			}
			else
			{
				for (int i = 0; i < player.myitems.size(); i++)
				{
					cout << i << " - sprzedaj " << (*player.items[i]).name << endl;
					cout << "	+ " << (*player.items[i]).addmaxhp << " maksymalnego zycia" << endl;
					cout << "	+ " << (*player.items[i]).addstrength << " sily" << endl;
					cout << "	+ " << (*player.items[i]).addbspace << " miejsca w ekwipunku" << endl;
					cout << "	+ " << (*player.items[i]).addbelt << " miejsca na pasku z miksturami" << endl;
					cout << "	wartosc: " << (*player.items[i]).value << " zlota" << endl;
				}
			}

			cout << endl;

			cout << "Mikstury:" << endl;
			if (player.potions.size() == 0)
			{
				cout << "Brak misktur" << endl;
			}
			else
			{
				for (int j = 97; j < (97 + player.potions.size()); j++)
				{
					cout << (char)j << " - sprzedaj " << (*player.potions[j - 97]).name << endl;
					cout << "	+ " << (*player.potions[j - 97]).addzy << "punktow zdrowia" << endl;
					cout << "	wartosc: " << (*player.potions[j - 97]).val << " zlota" << endl;
				}
			}

			cout << endl;
			cout << "Swoj wybor zatwierdz ENTERem." << endl;
			cout << "<dowolny znak> - aby nic nie sprzedac" << endl;

			cin >> znak3;

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// sprzedawanie

			Item* wsk;

			for (int i = 0; i < player.myitems.size(); i++)
			{
				if ((int)(znak3) == 48 + i)
				{
					wsk = player.items[i];
					wsk->sellitem(player);

				}
			}

			for (int j = 0; j < player.mypotions.size(); j++)
			{
				if ((int)(znak3) == 97 + j)
				{
					wsk = player.potions[j];
					wsk->sellitem(player);

				}
			}

			Sleep(3000);
			system("cls");



			break;

		case 'b':

			system("cls");
			cout << "Dostepne zloto: " << player.gold << endl;
			cout << endl;

			cout << "Przedmioty:" << endl;

			for (int i = 0; i < 3; i++)
			{
				cout << "   " << i << " - kup " << tab[i].name << endl;
				cout << "	+ " << tab[i].addmaxhp << " maksymalnego zycia" << endl;
				cout << "	+ " << tab[i].addstrength << " sily" << endl;
				cout << "	+ " << tab[i].addbspace << " miejsca w ekwipunku" << endl;
				cout << "	+ " << tab[i].addbelt << " miejsca na pasku z miksturami" << endl;
				cout << "	wartosc: " << tab[i].value << " zlota" << endl;
			}

			cout << endl;
			cout << "Mikstury:" << endl;
			for (int j = 3; j < 6; j++)
			{
				cout << "   " << j << " - kup " << tab1[j - 3].name << endl;
				cout << "	+ " << tab1[j - 3].addzy << "punktow zdrowia" << endl;
				cout << "	wartosc: " << tab1[j - 3].val << " zlota" << endl;
			}

			cout << endl;
			cout << "Swoj wybor zatwierdz ENTERem." << endl;
			cout << "<dowolny znak> - aby nic nie kupic" << endl;

			cin >> znak2;
			//znak2 = _getch();

			if (znak2 == '0')
			{
				if (player.sumbspace() < 1)
				{
					cout << "Brak miejsca w plecaku" << endl;
					Sleep(3000);
					system("cls");
				}
				else
				{
					if (tab[0].inbp == 1)
					{
						cout << "Mozesz posiadac tylko jeden taki przedmiot!" << endl;
						Sleep(3000);
						system("cls");
					}
					else
					{

						if (player.gold < tab[0].value)
						{
							cout << "Nie posiadasz wystarczajacej ilosci zlota" << endl;
							Sleep(3000);
							system("cls");
						}
						else
						{
							tab[0].tobackpack(player);
							cout << "Kupiles " << tab[0].name << endl;
							player.gold -= tab[0].value;
							cout << "-" << tab[0].value << " zlota" << endl;
						}


						Sleep(3000);
						system("cls");
					}
				}

			}
			else if (znak2 == '1')
			{
				if (player.sumbspace() < 1)
				{
					cout << "Brak miejsca w plecaku" << endl;
					Sleep(3000);
					system("cls");
				}
				else
				{


					if (tab[1].inbp == 1)
					{
						cout << "Mozesz posiadac tylko jeden taki przedmiot!" << endl;
						Sleep(3000);
						system("cls");
					}
					else
					{

						if (player.gold < tab[1].value)
						{
							cout << "Nie posiadasz wystarczajacej ilosci zlota" << endl;
							Sleep(3000);
							system("cls");
						}
						else
						{
							tab[1].tobackpack(player);
							cout << "Kupiles " << tab[1].name << endl;
							player.gold -= tab[1].value;
							cout << "-" << tab[1].value << " zlota" << endl;
						}
						Sleep(3000);
						system("cls");
					}
				}

			}
			else if (znak2 == '2')
			{

				if (player.sumbspace() < 1)
				{
					cout << "Brak miejsca w plecaku" << endl;
					Sleep(3000);
					system("cls");
				}
				else
				{

					if (tab[2].inbp == 1)
					{
						cout << "Mozesz posiadac tylko jeden taki przedmiot!" << endl;
						Sleep(3000);
						system("cls");
					}
					else
					{

						if (player.gold < tab[2].value)
						{
							cout << "Nie posiadasz wystarczajacej ilosci zlota" << endl;
							Sleep(3000);
							system("cls");
						}
						else
						{
							tab[2].tobackpack(player);
							cout << "Kupiles " << tab[2].name << endl;
							player.gold -= tab[2].value;
							cout << "-" << tab[2].value << " zlota" << endl;
						}
						Sleep(3000);
						system("cls");
					}
				}
			}
			else if (znak2 == '3') //////////////////////////////////////////////////////////////// potiony
			{

				if (player.sumbeltspace() < 1)
				{
					cout << "Brak miejsca na pasku" << endl;
					Sleep(3000);
					system("cls");
				}
				else
				{

					if (player.gold < tab1[0].val)
					{
						cout << "Nie posiadasz wystarczajacej ilosci zlota" << endl;
						Sleep(3000);
						system("cls");
					}
					else
					{
						tab1[0].tobackpack(player);
						cout << "Kupiles " << tab1[0].name << endl;
						player.gold -= tab1[0].val;
						cout << "-" << tab1[0].val << " zlota" << endl;
					}
					Sleep(3000);
					system("cls");
				}
			}
			else if (znak2 == '4')
			{

				if (player.sumbeltspace() < 1)
				{
					cout << "Brak miejsca na pasku" << endl;
					Sleep(3000);
					system("cls");
				}
				else
				{

					if (player.gold < tab1[1].val)
					{
						cout << "Nie posiadasz wystarczajacej ilosci zlota" << endl;
						Sleep(3000);
						system("cls");
					}
					else
					{
						tab1[1].tobackpack(player);
						cout << "Kupiles " << tab1[1].name << endl;
						player.gold -= tab1[1].val;
						cout << "-" << tab1[1].val << " zlota" << endl;
					}
					Sleep(3000);
					system("cls");
				}
			}
			else if (znak2 == '5')
			{

				if (player.sumbeltspace() < 1)
				{
					cout << "Brak miejsca na pasku" << endl;
					Sleep(3000);
					system("cls");
				}
				else
				{

					if (player.gold < tab1[2].val)
					{
						cout << "Nie posiadasz wystarczajacej ilosci zlota" << endl;
						Sleep(3000);
						system("cls");
					}
					else
					{
						tab1[2].tobackpack(player);
						cout << "Kupiles " << tab1[2].name << endl;
						player.gold -= tab1[2].val;
						cout << "-" << tab1[2].val << " zlota" << endl;
					}
					Sleep(3000);
					system("cls");
				}
			}
			else
			{




				//Sleep(3000);
				system("cls");
			}



			break;

		default:

			exit = 1;

			system("cls");

			break;

		}
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void home(Player & player)
{
	bool exit = 0;

	while (exit == 0)
	{
		cout << endl;
		cout << "-----DOM-----" << endl;
		cout << "0 - aby odpoczac" << endl;
		cout << "1 - aby wyswietlic informacje o graczu" << endl;
		cout << "<dowolny klawisz> - aby wyjsc z domu" << endl;

		char znk = _getch();
		char zn = 'a';

		switch (znk)
		{

		case '0':
			system("cls");
			player.sleeep(tab2);

			cout << "Jestes wypoczety! Twoja energia: 100/100" << endl;
			Sleep(3000);
			system("cls");

			break;

		case'1':

			while (zn != 'e')
			{
				system("cls");
				player.introduce();
				player.myArtifacts();
				player.myPotions();
				cout << endl;
				cout << "e - aby wrocic do menu domu" << endl;
				zn = _getch();
			}
			system("cls");
			break;

		default:

			exit = 1;

			system("cls");
			break;
		}

	}
}

