// KoderBlokowy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Kanal.h"	//nagłówek z funkcją symulującą kanał
#include "Macierz.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#define N 29

using namespace std;

//bedzie liczba calkowita, ale moze int nie starczyc to sie przerobi na longa czy cos
int bledyBezKodowania(int *ciagKodowy, int *odebranyCiagKodowy) {
	int bledyBez = 0;
	for (int i = 0; i < N; i++) {
		if (*(ciagKodowy + i) != *(odebranyCiagKodowy + i)) {
			bledyBez+=1;
		}
		else
			continue;
	}
	return bledyBez;
}
int bledyZKodowaniem(int *ramka, int *ciagZdekodowany) {
	int bledyZK = 0;
	for (int i = 0; i < 24; i++) {
		if (*(ramka + i) != *(ciagZdekodowany + i)) {
			bledyZK++;
		}
		else
			continue;
	}
	return bledyZK;
}
int main()
{
	float bledyBezK = 0;
	float bledyZK = 0;
	float ciagWyjsciowyR[N];
	int ciagWyjsciowy[N];
	float minEsNo;
	float maxEsNo;
	float krok;
	int iloscRamek;
	fstream plik;
	float berBezK;
	float berZK;

	//oblicznie macierzy G i H
	Macierz macierz;
	macierz.wyznaczG();
	macierz.wyznaczH();
	
	//wczytanie danych przez użytkownika
	cout << "Wpisz minimalne Es/N0: " << endl;
	cin >> minEsNo;
	cout << "Wpisz maksymalne Es/N0: " << endl;
	cin >> maxEsNo;
	cout << "Wpisz krok zwieszania: " << endl;
	cin >> krok;
	cout << "Wpisz liczbe blokow danych: " << endl;
	cin >> iloscRamek;
	//stworzenie pliku do wyników
	plik.open("wyniki.txt", ios::out);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}
	plik << "Es/No [dB]" << setw(30) << "BER bez kodowania" << setw(30) << "BER z kodowaniem" << endl;
	plik.close();
	//główna pętla programu
	for (double i = minEsNo; i <= maxEsNo; i += krok) {
		for (int j = 0; j < iloscRamek; j++) {
			//wylosowanie ramki, wyznaczenie ciągu kodowego
			macierz.zakoduj();
			//symulacja kanału
			kanal(i, N, macierz.getCiag(), ciagWyjsciowyR);
			//detekcja
			for (int j = 0; j < N; j++)
			{
				if (ciagWyjsciowyR[j] > 0)
				{
					ciagWyjsciowy[j] = 1;
				}
				else
				{
					ciagWyjsciowy[j] = 0;
				}
			}
			//wyznaczenie błędów bez kodowania
			bledyBezK += bledyBezKodowania(macierz.getCiag(), ciagWyjsciowy);
			//odkodowanie, naprawienie błędu
			macierz.wyznaczCiagOdebrany(ciagWyjsciowy);
			//wyznaczenie błędów z kodowaniem
			bledyZK += bledyZKodowaniem(macierz.getRamka(), macierz.getCiagZdekodowany());
		}
		//obliczenie BER
		berBezK = bledyBezK / (29 * iloscRamek);
		berZK = bledyZK / (24 * iloscRamek);
		//zapis danych do pliku
		plik.open("wyniki.txt", ios::app);
		plik << i << setw(30) << berBezK << setw(30) << berZK << endl;
		plik.close();
		//wyzerowanie zmiennych
		berBezK = 0;
		berZK = 0;
		bledyBezK = 0;
		bledyZK = 0;
	}
	
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
