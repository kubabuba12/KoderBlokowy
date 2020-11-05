#pragma once
class Macierz
{
private:
	static const int N = 29;
	static const int K = 24;
	int macierzBledow[N][N - K];
	int wektoryP[K][N - K];
	int macierzG[K][N];
	int ciagKodowy[N];
	int ramka[K];
	int ciagOdebrany[N];
	int syndrom[N - K];
	int ciagZdekodowany[K];
	int macierzH[N][N - K];
	int macierzPT[K][N - K];
	int macierzHt[N][N - K] = {
	{1,0,0,0,0},
	{0,1,0,0,0},
	{1,1,0,0,0},
	{0,0,1,0,0},
	{1,0,1,0,0},
	{0,1,1,0,0},
	{1,1,1,0,0},
	{0,0,0,1,0},
	{1,0,0,1,0},
	{0,1,0,1,0},
	{1,1,0,1,0},
	{0,0,1,1,0},
	{1,0,1,1,0},
	{0,1,1,1,0},
	{1,1,1,1,0},
	{0,0,0,0,1},
	{1,0,0,0,1},
	{0,1,0,0,1},
	{1,1,0,0,1},
	{0,0,1,0,1},
	{1,0,1,0,1},
	{0,1,1,0,1},
	{1,1,1,0,1},
	{0,0,0,1,1},
	{1,0,0,1,1},
	{0,1,0,1,1},
	{1,1,0,1,1},
	{0,0,1,1,1},
	{1,0,1,1,1} };

public:
	Macierz();
	void wyznaczG();
	void wyznaczH();
	void wyznaczCiagOdebrany(int *);
	void wyznaczCiagKodowy(int *);
	void zakoduj();
	int* getCiag();
	int* getCiagOdebrany();
	int* getRamka();
	int* getCiagZdekodowany();
	~Macierz();
};

