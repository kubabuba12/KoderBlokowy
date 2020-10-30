#pragma once
class MacierzG
{
private:
	static const int N = 29;
	static const int K = 24;
	int macierzBledow[N][N - K];
	int wektoryP[K][N - K];
	int macierzG[K][N];
	int ciagKodowy[N];
	int ramka[K];
public:
	MacierzG();
	void wyznaczG();
	void wyznaczCiagKodowy(int *);
	void zakoduj();
	int* getCiag();
	int* getRamka();
	~MacierzG();
};

