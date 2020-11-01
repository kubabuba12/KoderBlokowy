#pragma once
class MacierzG
{
private:
	int macierzBledow[N][N - K];
	int wektoryP[K][N - K];
	int macierzPT[N-K][K]
	int macierzG[K][N];	
	int macierzH[N][K];
	int ciagKodowy[N];
	int ciagOdebrany[N];
	int ramka[K];
public:
	MacierzG();
	void wyznaczG();
	void wyznaczCiagKodowy(int *);
	void zakoduj();
	int* getCiag();
	int* getRamka();
	static const int N = 29;
	static const int K = 24;
	~MacierzG();
};

