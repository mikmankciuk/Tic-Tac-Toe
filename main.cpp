#include <iostream>
#include <stdlib.h>

#include "gra.h"

void menu();
char graJednoosobowa(int rozmiarPola, int warunekZwyciestwa, bool czyGraczZaczyna);

int main()
{
	int rozmiarGry = 3, warunekZwyciestwa =3;
	bool czyJednoosobowa = true, czyGraczZaczyna = true;
	char wynikGry;
	char pomocnicza = 'z';

	// petla po menu glownym
	while (pomocnicza != 3)
	{
		menu();
		while (pomocnicza != '1' && pomocnicza != '2' && pomocnicza != '3' && pomocnicza != '4')
		{
			std::cin >> pomocnicza;
			if (pomocnicza != '1' && pomocnicza != '2' && pomocnicza != '3' && pomocnicza != '4')
			{
				std::cout << "Wprowadz poprawna wartosc: ";
			}
		}
		switch (pomocnicza)
		{
		case '1':	//opcja w ktorej gre rozpoczyna gracz
			system("CLS");
			wynikGry = graJednoosobowa(rozmiarGry, warunekZwyciestwa, true);
			if (wynikGry == 'r')
			{
				std::cout << "Brak zwyciezcy!" << std::endl;
			}
			else
				if (wynikGry == 'X')
				{
					std::cout << "Zwycieza gracz!" << std::endl;
				}
				else
					if (wynikGry == 'O')
					{
						std::cout << "Zwycieza komputer!" << std::endl;
					}
			system("pause");
			pomocnicza = 'z';
			break;
		case '2':	// opcja w ktorej gre rozpoczyna AI
			system("CLS");
			wynikGry = graJednoosobowa(rozmiarGry, warunekZwyciestwa, false);
			if (wynikGry == 'r')
			{
				std::cout << "Brak zwyciezcy!" << std::endl;
			}
			else
				if (wynikGry == 'X')
				{
					std::cout << "Zwycieza gracz!" << std::endl;
				}
				else
					if (wynikGry == 'O')
					{
						std::cout << "Zwycieza komputer!" << std::endl;
					}
			system("pause");
			pomocnicza = 'z';
			break;
		case '3':	// ustawianie opji rozgrywki
			rozmiarGry = 0;
			warunekZwyciestwa = 0;
			pomocnicza = 'z';
			std::cout << "Wprowadz rozmiar rozgrywki (z przedzialu <3;16>): ";
			while (rozmiarGry < 3 || rozmiarGry > 16)
			{
				std::cin >> rozmiarGry;
				if (rozmiarGry < 3 || rozmiarGry > 16)
				{
					std::cout << "Wprowadz rozsadny rozmiar rozgrywki: ";
				}
			}
			std::cout << "Wprowadz warunek zwyciestwa (z przedzialu <2;rozmiar gry>): ";
			while (warunekZwyciestwa < 2 || warunekZwyciestwa > rozmiarGry)
			{
				std::cin >> warunekZwyciestwa;
				if (warunekZwyciestwa < 2 || warunekZwyciestwa > rozmiarGry)
				{
					std::cout << "Wprowadz rozsadny warunek zwyciestwa: ";
				}
			}
			break;
		case '4':	//wyjscie z programu
			return 0;
			break;
		}
	}
	return 0;
}

/// <summary>
/// wyswietlanie menu glownego
/// </summary>
void menu()
{
	system("CLS");
	std::cout << std::endl;
	std::cout << "##############################" << std::endl << "##############################" << std::endl << "##                          ##"
		<< std::endl << "##  [1] gracz zaczyna       ##" << std::endl << "##  [2] komputer zaczyna    ##" << std::endl << "##  [3] zmiana zasad        ##" 
		<< std::endl << "##  [4] wyjscie             ##" << std::endl << "##   		            ##" 
		<< std::endl << "##############################" << std::endl << "##############################" << std::endl << "> ";
}

/// <summary>
/// funkcja rozpoczynajaca rozgrywke
/// </summary>
/// <param name="rozmiarGry"></param>
/// <param name="warunekZwyciestwa"></param>
/// <param name="czyGraczZaczyna"></param>
/// <returns></returns>
char graJednoosobowa(int rozmiarGry, int warunekZwyciestwa, bool czyGraczZaczyna)
{
	gra test(rozmiarGry, warunekZwyciestwa, czyGraczZaczyna);
	test.resetuj();
	char rezultat = 'P';
	int porazkaAI = 0;

	if (czyGraczZaczyna == true)
	{
		while (rezultat != 'X' && rezultat != 'O' && porazkaAI != 1)
		{
			test.wyswietlPlansze();
			test.ruchGracza();
			system("CLS");
			rezultat = test.sprawdz();
			if (rezultat == 'X')
			{
				test.wyswietlPlansze();
				return rezultat;
			}
			else
				if (rezultat == 'r')
				{
					test.wyswietlPlansze();
					return rezultat;
				}

			test.wyswietlPlansze();
			porazkaAI = test.ruchAI();
			system("CLS");
			rezultat = test.sprawdz();
			if (rezultat == 'O')
			{
				test.wyswietlPlansze();
				return rezultat;
			}
			else
				if (rezultat == 'r')
				{
					test.wyswietlPlansze();
					return rezultat;
				}
				else
					if (porazkaAI == 1)
					{
						test.wyswietlPlansze();
						return 'X';
					}
		}
	}
	else
	{
		while (rezultat != 'X' && rezultat != 'O' && porazkaAI != 1)
		{
			test.wyswietlPlansze();
			porazkaAI = test.ruchAI();
			system("CLS");
			rezultat = test.sprawdz();
			if (rezultat == 'O')
			{
				test.wyswietlPlansze();
				return rezultat;
			}
			else
				if (rezultat == 'r')
				{
					test.wyswietlPlansze();
					return rezultat;
				}
				else
					if (porazkaAI == 1)
					{
						test.wyswietlPlansze();
						return 'X';
					}

			test.wyswietlPlansze();
			test.ruchGracza();
			system("CLS");
			rezultat = test.sprawdz();
			if (rezultat == 'X')
			{
				test.wyswietlPlansze();
				return rezultat;
			}
			else
				if (rezultat == 'r')
				{
					test.wyswietlPlansze();
					return rezultat;
				}
		}
	}
	return 'r';
}