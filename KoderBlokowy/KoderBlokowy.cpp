// KoderBlokowy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Kanal.h"	//nagłówek z funkcją symulującą kanał
#include "Macierz.h"
#include <iostream>
#include <math.h>
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
	int bledyBezK;
	int bledyZK;
	int es_n0;
	float ciagWyjsciowyR[N];
	int ciagWyjsciowy[N];
	//int ciagZdekodowany[K];

	Macierz macierz;
	macierz.wyznaczG();
	macierz.wyznaczH();
	macierz.zakoduj();

	cout << "Wpisz Es/N0: " << endl;
	cin >> es_n0;

	for (int i = 0; i < N; i++)
	{
		ciagWyjsciowyR[i] = 0;
	}

	kanal(es_n0, N, macierz.getCiag(), ciagWyjsciowyR);

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
	bledyBezK = bledyBezKodowania(macierz.getCiag(), ciagWyjsciowy);

	macierz.wyznaczCiagOdebrany(ciagWyjsciowy);

	bledyZK = bledyZKodowaniem(macierz.getRamka(), macierz.getCiagZdekodowany());

	//do testu
	cout << "Ciag kodowy:";
	for (int i = 0; i < 29; i++)
		cout << *(macierz.getCiag() + i);
	cout << endl << "ramka: ";
	for (int i = 0; i < 24; i++)
		cout << *(macierz.getRamka() + i);
	cout << endl << "Ciag Wyjsciowy:";
	for (int i = 0; i < 29; i++)
		cout << ciagWyjsciowy[i];
	cout << endl << "Ciag Zdekodowany:";
	for (int i = 0; i < 24; i++)
		cout << *(macierz.getCiagZdekodowany()+i);
	cout << endl << "Bledy bezK: " << bledyBezK << endl;
	cout << "Bledy zK: " << bledyZK;

	//Tutaj petla programu
	//	for, albo while zalezy jaki warunek
	//	1. wylosowanie ramki, zakodowanie -> macierzG.zakoduj();
	//	2. ciag kodowy do kanalu
	//	3. detekcja
	//	4. porównanie ciągów bez kodowania
		

	//	5. dekodowanie
	//	6. porównanie z kodowaniem
	//	bledyZK = bledyZKodowaniem(macierzG.getRamka(), zdekodowany);

	//	7. wyznaczenie wartosci ber
	//int berBezK = bledyBezK / (29 * liczbaPetli);
	//int berZK = bledyZK / (24 * liczbaPetli);
	
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
