#include "gra.h"
#include <algorithm>

gra::gra(int rozmiarGry, int warunekZwyciestwa, bool czyplanszaczZaczyna)
{
	this->rozmiar = rozmiarGry;
	this->dlugosc = warunekZwyciestwa;
	this->stanGry = new char* [rozmiar];
	for (int indeks = 0; indeks < rozmiar; indeks++)
	{
		stanGry[indeks] = new char[rozmiar];
	}
}

void gra::resetuj()
{
	for (int kolumna = 0; kolumna < rozmiar; kolumna++)
	{
		for (int wiersz = 0; wiersz < rozmiar; wiersz++)
		{
			stanGry[kolumna][wiersz] = ' ';
		}
	}
}

void gra::wyswietlPlansze()
{

	for (int kolumna = 0; kolumna < rozmiar - 1; kolumna++)
	{
		for (int wiersz = 0; wiersz < rozmiar - 1; wiersz++)
		{
			std::cout << "  " << stanGry[kolumna][wiersz] << "  " << "|";
		}
		std::cout << "  " << stanGry[kolumna][rozmiar - 1] << "  " << std::endl;

		for (int licznik = rozmiar * 5 + rozmiar - 1; licznik > 0; licznik--)
		{
			std::cout << "-";
		}
		std::cout << std::endl;

	}
	for (int wiersz = 0; wiersz < rozmiar - 1; wiersz++)
	{
		std::cout << "  " << stanGry[rozmiar - 1][wiersz] << "  " << "|";
	}

	std::cout << "  " << stanGry[rozmiar - 1][rozmiar - 1] << "  " << std::endl;

}

void gra::ruchGracza()
{
	int k = 0, w = 0;
	bool niepoprawnePole = false;
	std::cout << "Tura Gracza. Podaj wspolrzedne w ktore chcesz wpisac znak." << std::endl;
	do
	{
		do
		{
			std::cout << " wiersz: ";
			std::cin >> w;
		} while (w < 0 || w >= rozmiar);
		do
		{
			std::cout << " kolumna: ";
			std::cin >> k;
		} while (k < 0 || k >= rozmiar);

		if (stanGry[w][k] != ' ')
		{
			niepoprawnePole = true;
		}
		if (niepoprawnePole == true)
		{
			std::cout << "Podano niepoprawne pole. Wybierz poprawne pole." << std::endl;
			niepoprawnePole = false;
		}
	} while (stanGry[w][k] != ' ');
	stanGry[w][k] = 'X';
}

char gra::sprawdz()
{
	int licznikO = 0, licznikX = 0;

	//=======================
	// sprawdzanie pionu/poziomu
	//=======================

	for (int kolumna = 0; kolumna < rozmiar; kolumna++)
	{
		licznikO = 0;
		licznikX = 0;
		for (int wiersz = 0; wiersz < rozmiar; wiersz++)
		{
			if (stanGry[kolumna][wiersz] == ' ')
			{
				licznikO = 0;
				licznikX = 0;
			}
			else
				if (stanGry[kolumna][wiersz] == 'X')
				{
					licznikX++;
					licznikO = 0;
				}
				else
					if (stanGry[kolumna][wiersz] == 'O')
					{
						licznikO++;
						licznikX = 0;
					}
			if (licznikO == dlugosc)
			{
				return 'O';
			}
			if (licznikX == dlugosc)
			{
				return 'X';
			}
		}
	}

	for (int wiersz = 0; wiersz < rozmiar; wiersz++)
	{
		licznikO = 0;
		licznikX = 0;
		for (int kolumna = 0; kolumna < rozmiar; kolumna++)
		{
			if (stanGry[kolumna][wiersz] == ' ')
			{
				licznikO = 0;
				licznikX = 0;
			}
			else
				if (stanGry[kolumna][wiersz] == 'X')
				{
					licznikX++;
					licznikO = 0;
				}
				else
					if (stanGry[kolumna][wiersz] == 'O')
					{
						licznikO++;
						licznikX = 0;
					}
			if (licznikO == dlugosc)
			{
				return 'O';
			}
			if (licznikX == dlugosc)
			{
				return 'X';
			}
		}
	}

	//=======================
	// sprawdzanie skosow
	//=======================

	for (int wiersz = rozmiar - dlugosc; wiersz > -1; wiersz--)
	{
		licznikO = 0;
		licznikX = 0;
		for (int licznik = 0; licznik < rozmiar - wiersz; licznik++)
		{
			if (stanGry[licznik][wiersz + licznik] == ' ')
			{
				licznikO = 0;
				licznikX = 0;
			}
			else
				if (stanGry[licznik][wiersz + licznik] == 'X')
				{
					licznikX++;
					licznikO = 0;
				}
				else
					if (stanGry[licznik][wiersz + licznik] == 'O')
					{
						licznikO++;
						licznikX = 0;
					}
			if (licznikO == dlugosc)
			{
				return 'O';
			}
			if (licznikX == dlugosc)
			{
				return 'X';
			}
		}
	}

	for (int kolumna = rozmiar - dlugosc; kolumna > 0; kolumna--)
	{
		licznikO = 0;
		licznikX = 0;
		for (int licznik = 0; licznik < rozmiar - kolumna; licznik++)
		{
			if (stanGry[kolumna + licznik][licznik] == ' ')
			{
				licznikO = 0;
				licznikX = 0;
			}
			else
				if (stanGry[kolumna + licznik][licznik] == 'X')
				{
					licznikX++;
					licznikO = 0;
				}
				else
					if (stanGry[kolumna + licznik][licznik] == 'O')
					{
						licznikO++;
						licznikX = 0;
					}
			if (licznikO == dlugosc)
			{
				return 'O';
			}
			if (licznikX == dlugosc)
			{
				return 'X';
			}
		}
	}

	for (int wiersz = dlugosc - 1; wiersz < rozmiar; wiersz++)
	{
		licznikO = 0;
		licznikX = 0;
		for (int licznik = 0; wiersz - licznik > -1; licznik++)
		{
			if (stanGry[wiersz - licznik][licznik] == ' ')
			{
				licznikO = 0;
				licznikX = 0;
			}
			else
				if (stanGry[wiersz - licznik][licznik] == 'X')
				{
					licznikX++;
					licznikO = 0;
				}
				else
					if (stanGry[wiersz - licznik][licznik] == 'O')
					{
						licznikO++;
						licznikX = 0;
					}
			if (licznikO == dlugosc)
			{
				return 'O';
			}
			if (licznikX == dlugosc)
			{
				return 'X';
			}
		}
	}

	for (int kolumna = rozmiar - dlugosc; kolumna > 0; kolumna--)
	{
		licznikO = 0;
		licznikX = 0;
		for (int licznik = 0; licznik < rozmiar - kolumna; licznik++)
		{
			if (stanGry[rozmiar - 1 - licznik][kolumna + licznik] == ' ')
			{
				licznikO = 0;
				licznikX = 0;
			}
			else
				if (stanGry[rozmiar - 1 - licznik][kolumna + licznik] == 'X')
				{
					licznikX++;
					licznikO = 0;
				}
				else
					if (stanGry[rozmiar - 1 - licznik][kolumna + licznik] == 'O')
					{
						licznikO++;
						licznikX = 0;
					}
			if (licznikO == dlugosc)
			{
				return 'O';
			}
			if (licznikX == dlugosc)
			{
				return 'X';
			}
		}
	}

	int licznik = 0;
	for (int kolumna = 0; kolumna < rozmiar; kolumna++)
	{
		for (int wiersz = 0; wiersz < rozmiar; wiersz++)
		{
			if (stanGry[kolumna][wiersz] != ' ')
			{
				licznik++;
			}
		}
	}
	if (licznik == rozmiar * rozmiar)
	{
		return 'r';
	}

	return ' ';
}

bool gra::czyPoleDostepne(char** tablica, int i, int j)
{
	if (tablica[i][j] == ' ')
	{
		return true;
	}
	return false;
}

bool gra::czySasiad(char** tablica, int wiersz, int kolumna, int promien)
{
	for (int i = wiersz - promien; i <= wiersz + promien; i++)
	{
		for (int j = kolumna - promien; j <= kolumna + promien; j++)
		{
			if (i >= 0 && i < rozmiar && j >= 0 && j < rozmiar)
			{
				if (!czyPoleDostepne(tablica, i, j))
				{
					return true;
				}
			}
		}
	}
	return false;
}

int gra::ruchAI()
{
	int srodek = rozmiar / 2;
	if(czyPoleDostepne(stanGry, srodek, srodek))									// jezeli dostepne jest pole na srodku wykonuje tam ruch
	{																				// w przeciwnym razie wykonuje minimax
		stanGry[srodek][srodek] = 'O';
	}
	else
	{
		int ocenaNajlepszegoRuchu = -10;
		int ocenaRuchu = 0;
		int* najlepszyRuch = new int[2];
		najlepszyRuch[0] = 0;
		najlepszyRuch[1] = 0;
		bool czyPorazka = true;

		for (int kolumna = 0; kolumna < rozmiar; kolumna++)
		{
			std::cout << ".";
			for (int wiersz = 0; wiersz < rozmiar; wiersz++)
			{
				if (czyPoleDostepne(stanGry, kolumna, wiersz))
				{
					if (czySasiad(stanGry, wiersz, kolumna, dlugosc - 1))			// jezeli w promieniu nie ma sasiadow to nie warto rozwazac pola
					{
						stanGry[kolumna][wiersz] = 'O';
						ocenaRuchu = minimax(-10, 10, false, 2 * dlugosc);
						std::cout << " " << ocenaRuchu << " ";
						stanGry[kolumna][wiersz] = ' ';
					}
					if (ocenaRuchu > ocenaNajlepszegoRuchu)							// jezeli ruch jest bardziej optymalny to go zapamietaj
					{
						czyPorazka = false;											// patrz linia 404
						ocenaNajlepszegoRuchu = ocenaRuchu;
						najlepszyRuch[0] = kolumna;
						najlepszyRuch[1] = wiersz;
					}
				}
			}
		}
		if (czyPorazka == false && ocenaNajlepszegoRuchu != -1)						// poddaje sie jezeli kazdy ruch doprowadzi do przegranej
		{
			stanGry[najlepszyRuch[0]][najlepszyRuch[1]] = 'O';
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int gra::minimax(int alfa, int beta, bool czyMax, int glebokoscRekurencji)
{
	char wynik = sprawdz();															// sprawdza czy nastapil koniec rozgrywki i jezeli tak
	if (wynik == 'r')																// zwraca odpowiednia wartosc
	{
		return 0;
	}	else
		if (wynik == 'X')
		{
			return -1;
		}	else
			if (wynik == 'O')
			{
				return 1;
			}	else
				if (glebokoscRekurencji == 0)										// jezeli przekroczy limit rekurencji traktuje to jako remis
				{
					return 0;
				}	else
	if (czyMax == true)																// czesc maksymalizujaca algorytmu minimax
	{
		int ocenaNajlepszegoRuchu = -10;
		int ocenaRuchu;
		for (int kolumna = 0; kolumna < rozmiar; kolumna++)
		{
			for (int wiersz = 0; wiersz < rozmiar; wiersz++)
			{
				if (czyPoleDostepne(stanGry, kolumna, wiersz))
				{
					stanGry[kolumna][wiersz] = 'O';
					ocenaRuchu = minimax(alfa, beta, false, glebokoscRekurencji - 1);
					stanGry[kolumna][wiersz] = ' ';
					ocenaNajlepszegoRuchu = std::max(ocenaRuchu, ocenaNajlepszegoRuchu);
					alfa = std::max(alfa, ocenaRuchu);
					if (beta <= alfa)												// ciecia alfa-beta
					{
						return ocenaNajlepszegoRuchu;
					}
				}
			}
		}
		return ocenaNajlepszegoRuchu;
	}
	else																			// czesc minimalizujaca algorytmu minimax
	{
		int ocenaNajlepszegoRuchu = 10;
		int ocenaRuchu;
		for (int kolumna = 0; kolumna < rozmiar; kolumna++)
		{
			for (int wiersz = 0; wiersz < rozmiar; wiersz++)
			{
				if (czyPoleDostepne(stanGry, kolumna, wiersz))
				{
					stanGry[kolumna][wiersz] = 'X';
					ocenaRuchu = minimax(alfa, beta, true, glebokoscRekurencji - 1);
					stanGry[kolumna][wiersz] = ' ';
					ocenaNajlepszegoRuchu = std::min(ocenaRuchu, ocenaNajlepszegoRuchu);
					beta = std::min(beta, ocenaRuchu);								
					if (beta <= alfa)												// ciecia alfa-beta
					{
						return ocenaNajlepszegoRuchu;
					}
				}
			}
		}
		return ocenaNajlepszegoRuchu;
	}
}