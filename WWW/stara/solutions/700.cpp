// KonkatenacjaG4.cpp : Defines the entry point for the console application.
//
// KonkatenacjaG3.cpp : Defines the entry point for the console application.
//

#include<cstdio>

using namespace std;

const int RM = 209;
int waga[RM][RM]; // zaczyna sie w msc first, i ma dlugosc K , tzn K+1 wierzcholkow,
int wyniki[RM][RM]; // jak wyzej
int nawiasy[RM][RM]; // jak wyzej, ile nawiasow juz wykorzystuje


int main()
{
	int zw;
	scanf("%d", &zw);
	while(zw--)
	{
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{		
			scanf("%d", &waga[i][0]);
			wyniki[i][0] = 0;
			nawiasy[i][0] = 0;
		}
		int k;
		int tempNaw;
		int tempWyn;
		int actWyn;
		int actNaw;
		for(int i=1; i<n; i++) // dla kazdej dlugosci
		{
			for(int j=0; j<n-i; j++) // wybierz poczatek 
			{
				waga[j][i] = waga[j][0]+waga[p][i-1];
//				if(i+j<n)
					for(int p=j+1; p <= j+i; p++) // mozliwy 'srodek', srodek juz nalezy do part 2
					{
//						if(p==j+1) waga[j][i] = waga[j][p-j-1]+waga[p][k-p];
						k = i+j; //koniec
						tempNaw = nawiasy[j][p-j-1]+nawiasy[p][k-p]; // potencjalnie nowa liczba nawiasow
						if(k!=p) tempNaw+=1;
						tempWyn = wyniki[j][p-j-1]+/*waga[j][p-j-1]+waga[p][k-p]*/+wyniki[p][k-p]+waga[j][i]; // potencjalny wynik
						actWyn = wyniki[j][i];
						actNaw = nawiasy[j][i];

						if(p==j+1 || actWyn > tempWyn || (actWyn == tempWyn && actNaw>tempNaw)  )
						{
							wyniki[j][i]=tempWyn;
							nawiasy[j][i] = tempNaw;
//							waga[j][i] = waga[j][p-j-1]+waga[p][k-p];
						}
					}
			}
		}
		printf("%d %d\n", wyniki[0][n-1], nawiasy[0][n-1]);
	}
	return 0;
}