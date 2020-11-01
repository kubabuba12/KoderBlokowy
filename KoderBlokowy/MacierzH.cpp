#include "pch.h"
#include "MacierzG.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
MacierzH::MacierzH()
{
}

void MacierzH::wyznaczH()
{
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
	
	for(int i = 0; i < N-K; i++)
	{
		for(int j = 0; j < K; j++)
		{
			macierzPT[j][i] = wektoryP[i][j];
		}
	}
	
	
	//WektoryP + macierz I => macierz Ht
	//int macierzH[N][K];
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < K; i++) {
			if (j > 5) {
				macierzHt[i][j] = MacierzPT[i][j];
			}
			else if (i == j - 5) {
				macierzH[i][j] = 1;
			}
			else
				macierzH[i][j] = 0;
		}
	}
}

void MacierzHt::wyznaczCiagOdebrany(int *ciag) {
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < K; j++) {
			tmp += *(ciag + j)*macierzH[j][i];
		}
		ciagOdebrany[i] = tmp;
	}
}

int* MacierzHt::getCiagOdebrany() {
	return ciagOdebrany;
}
