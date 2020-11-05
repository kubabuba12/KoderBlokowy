#include "pch.h"
#include "Macierz.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;
Macierz::Macierz()
{
}
void Macierz::wyznaczG() {
	//int macierzBledow[N][N - K];
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
	//int wektoryP[K][N - K];
	//wektory ortogonalne to wiersze 1,2,4,8,16,32... potêgi 2 (nie wiem jak to zapisaæ)
	for (int j = 4; j >= 0; j--) {
		int licznik = 0;
		for (int i = 0; i < N; i++) {
			if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15)
				continue;
			else {
				wektoryP[licznik][-1 * (j - 4)] = macierzBledow[i][j];
				licznik++;
			}
		}
	}
	//WektoryP + macierz I => macierz generujaca G[P;I]
	//int macierzG[K][N];
	int licznik = 0;
	int licznik2 = 0;
	//Przemieszanie kolejnoœci kolumn w macierzyG(tak aby by³y jak p. Agnieszka mówi³a)
	for (int j = 0; j < N; j++) {
		bool x = true;
		bool y = false;
		for (int i = 0; i < K; i++) {
			if (j == 0 || j == 1 || j == 3 || j == 7 || j == 15) {
				macierzG[i][j] = wektoryP[i][licznik2];
				x = false;
				y = true;
			}
			else if (i == licznik) {
				macierzG[licznik][j] = 1;
			}
			else
				macierzG[i][j] = 0;
		}
		if(x)
			licznik++;
		if (y)
			licznik2++;
	}
}
void Macierz::zakoduj() {
	srand(time(NULL));
	for (int i = 0; i < K; i++) {
		ramka[i] = rand() % 2;
	}
	wyznaczCiagKodowy(ramka);
}
void Macierz::wyznaczCiagKodowy(int *informacja) {
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < K; j++) {
			tmp += *(informacja + j)*macierzG[j][i];
		}
		ciagKodowy[i] = tmp % 2;
	}
}
void Macierz::wyznaczH() {
	//Transponowanie P
	for (int i = 0; i < N - K; i++)
	{
		for (int j = 0; j < K; j++)
		{
			macierzPT[j][i] = wektoryP[i][j];
		}
	}
}
void Macierz::wyznaczCiagOdebrany(int* ciag) {
	int miejsceBledu = 0;
	bool blad = false;
	for (int i = 0; i < N-K; i++) {
		int tmp = 0;
		for (int j = 0; j < N; j++) {
			tmp += *(ciag + j)*macierzHt[j][i];
		}
		syndrom[i] = tmp % 2;
	}
	for (int i = 0; i < N - K; i++) {
		if (syndrom[i] != 0) {
			blad = true;
			miejsceBledu += pow(2, i);
		}
	}
	if (blad) {
		if (*(ciag + miejsceBledu-1) == 0)
			*(ciag + miejsceBledu-1) = 1;
		else
			*(ciag + miejsceBledu-1) = 0;
	}
	//wyznaczenie ci¹gu po dekodowaniu
	int licznik = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15)
			continue;
		else {
			ciagZdekodowany[licznik] = *(ciag + i);
			licznik++;
		}
	}
}
int* Macierz::getCiagOdebrany() {
	return ciagOdebrany;
}
int* Macierz::getCiag() {
	return ciagKodowy;
}
int* Macierz::getRamka() {
	return ramka;
}
int* Macierz::getCiagZdekodowany() {
	return ciagZdekodowany;
}
Macierz::~Macierz()
{
}
