#include "pch.h"
#include "MacierzG.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
MacierzG::MacierzG()
{
}
void MacierzG::wyznaczG() {
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
void MacierzG::zakoduj() {
	int ramka[K];
	srand(time(NULL));
	for (int i = 0; i < K; i++) {
		ramka[i] = rand() % 2;
	}
	wyznaczCiagKodowy(ramka);
}
void MacierzG::wyznaczCiagKodowy(int *informacja) {
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < K; j++) {
			tmp += *(informacja + j)*macierzG[j][i];
		}
		ciagKodowy[i] = tmp % 2;
	}
}
int* MacierzG::getCiag() {
	return ciagKodowy;
}
MacierzG::~MacierzG()
{
}
