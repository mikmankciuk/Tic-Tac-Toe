#pragma once
#include <iostream>

class gra
{
public:
	int rozmiar;			// rozmiar rozgrywki
	int dlugosc;			// dlugosc znakow potrzebna do wygrania
	char** stanGry;			// tablica przechowujaca stan gry

	/// <summary>
	/// konstruktor klasy gra
	/// </summary>
	/// <param name="rozmiarGry"></param>
	/// <param name="warunekZwyciestwa"></param>
	/// <param name="czyplanszaczZaczyna"></param>
	gra(int rozmiarGry, int warunekZwyciestwa, bool czyplanszaczZaczyna);

	/// <summary>
	/// funkcja resetuje stan gry
	/// </summary>
	void resetuj();

	/// <summary>
	/// funkcja wyswietla plansze gry
	/// </summary>
	void wyswietlPlansze();

	/// <summary>
	/// funkcja sprawdza obecny stan rozgrywki
	/// </summary>
	/// <returns>
	/// X - obecny stan oznacza wygrana gracza, 
	/// O - obecny stan oznacza wygrana AI, 
	/// r - remis, 
	/// ' ' - brak rezultatu
	/// </returns>
	char sprawdz();

	/// <summary>
	/// funckja sprawdza czy zadane pole w tablicy jest dostepne
	/// </summary>
	/// <param name="tablica"> zadana tablica </param>
	/// <param name="i"> zadana wspolrzedna </param>
	/// <param name="j"> zadana wspolrzedna </param>
	/// <returns></returns>
	bool czyPoleDostepne(char** tablica, int i, int j);

	/// <summary>
	/// funkcja sprawdza czy w promieniu od pola znajduje sie inne zajete pole
	/// </summary>
	/// <param name="tablica"> aktualny stan gry </param>
	/// <param name="wiersz"></param>
	/// <param name="kolumna"></param>
	/// <param name="promien"> - przeszukiwany zakres pol </param>
	/// <returns></returns>
	bool czySasiad(char** tablica, int wiersz, int kolumna, int promien);

	/// <summary>
	/// funkcja pozwalajaca graczowi wykonac ruch
	/// </summary>
	void ruchGracza();

	/// <summary>
	/// funkcja ruchu AI
	/// </summary>
	/// <returns>
	/// 1 - ai przegra niezaleznie od swojego ruchu; 
	/// 0 - rozgrywka ma sens kontynuacji
	/// </returns>
	int ruchAI();

	/// <summary>
	/// algorytm decyzyjny minimax
	/// </summary>
	/// <param name="alfa"></param>
	/// <param name="beta"></param>
	/// <param name="czyMax"></param>
	/// <returns></returns>
	int minimax(int alfa, int beta, bool czyMax, int glebokoscRekurencji);

};
