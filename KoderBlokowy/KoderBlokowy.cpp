// KoderBlokowy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Kanal.h"	//nagłówek z funkcją symulującą kanał
#include <iostream>
#include <math.h>
#define K 24	//długość wiadomości
#define N 29	//długość ciągu kodowego
using namespace std;



/*
do tego najlepiej klaskę by zrobic -> Macierz P
*/
//****** To tylko raz na początku uruchamiania programu ******
void macierzP() {
	int macierzBledow[N][N-K];
	for (int i = 0; i < N; i++) {
		int liczba = i + 1;
		for (int j = 4; j >= 0; j--) {
			if (liczba != 0) {
				macierzBledow[i][j] = liczba % 2;
				liczba /= 2;
			}
			else {
				macierzBledow[i][j] = 0;
			}
			
		}
	}
	int wektoryP[K][N-K];
	//wektory ortogonalne to wiersze 1,2,4,8,16,32... potęgi 2 (nie wiem jak to zapisać)
	for (int j = 4; j >= 0; j--) {
		int licznik = 0;
		for (int i = 0; i < N; i++) {
			if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15)
				continue;
			else {
				wektoryP[licznik][-1*(j-4)] = macierzBledow[i][j];
				licznik++;
			}
		}
	}
	//WektoryP + macierz I => macierz generujaca G[P;I]
	int macierzG[K][N];
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < K; i++) {
			if (j < 5) {
				macierzG[i][j] = wektoryP[i][j];
			}
			else if (i == j - 5) {
				macierzG[i][j] = 1;
			}
			else
				macierzG[i][j] = 0;
		}
	}
}
//****************************************
/*
ciągi wiadomości po 24 bity
*/
void losujRamke()
{
	int ramka[K];
	srand(time(NULL));
	for (int i = 0; i < K; i++) {
		ramka[i] = rand() % 2;
		cout << ramka[i];
	}
}

int main()
{
    cout << "Hello World!\n"; 
	//losujRamke();
	macierzP();
	//losujRamke();
	
	
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
