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
			scanf("%d", &waga[i][0]);
		for(int i=0; i<n; i++)
		{
			wyniki[i][0] = 0;
			nawiasy[i][0] = 0;
		}
		for(int i=0; i<n; i++)
		{		
			for(int j=1; j<n; j++)
			{
				wyniki[i][j] = -1;
				nawiasy[i][j] = -1;
			}
		}
		int k;
		int tempNaw;
		for(int i=1; i<n; i++) // dla kazdej dlugosci
		{
			for(int j=0; j<n-i; j++) // wybierz poczatek 
//				if(i+j<n)
					for(int p=j+1; p <= j+i; p++) // mozliwy 'srodek', srodek juz nalezy do part 2
					{
						k = i+j; //koniec
						tempNaw = nawiasy[j][p-j-1]+nawiasy[p][k-p]; // potencjalnie nowa liczba nawiasow
						if(k!=p) tempNaw+=1;

						if(wyniki[j][i]==-1 || wyniki[j][i] > wyniki[j][p-j-1]+waga[j][p-j-1]+waga[p][k-p]+wyniki[p][k-p] || (wyniki[j][i] == wyniki[j][p-j-1]+waga[j][p-j-1]+waga[p][k-p]+wyniki[p][k-p] && nawiasy[j][i]>tempNaw)  )
						{
							wyniki[j][i]=wyniki[j][p-j-1]+waga[j][p-j-1]+waga[p][k-p]+wyniki[p][k-p];
							nawiasy[j][i] = tempNaw;
							waga[j][i] = waga[j][p-j-1]+waga[p][k-p];
						}
					}
		}
		printf("%d %d\n", wyniki[0][n-1], nawiasy[0][n-1]);
	}
	return 0;
}