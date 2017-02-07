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
		for(int j=1; j<n; j++)
		{
			wyniki[i][j] = -1;
			nawiasy[i][j] = -1;
		}

		for(int i=1; i<n; i++) // dla kazdej dlugosci
		{
//			printf("teraz i %d\n", i);
			for(int j=0; j<n; j++) // wybierz poczatek 
				if(i+j<n)
				for(int p=j+1; p<n && p <= j+i; p++) // mozliwy 'srodek', srodek juz nalezy do part 2
					{
			//			printf("************ ja pierdole ********** %d\n", waga[1][0]);

						int k = i+j; //koniec
			//			printf("dla danych: %d %d %d, akt wynik wynosi %d\n", i, j, p, wyniki[j][i]);
						if(wyniki[j][i]==-1 || wyniki[j][i] >= wyniki[j][p-j-1]+waga[j][p-j-1]+waga[p][k-p]+wyniki[p][k-p])
						{
//							printf("no i wchodze!!!\n");
							wyniki[j][i]=wyniki[j][p-j-1]+waga[j][p-j-1]+waga[p][k-p]+wyniki[p][k-p];
//							printf("no i mam kuzwa nowy wynik %d\n", wyniki[j][i]);
//							printf("skadowe wyniku: p1 %d p2 %d w1 %d w2 %d\n", wyniki[j][p-j-1], wyniki[p][k-p], waga[j][p-j-1], waga[p][k-p]);
//							printf("beg1 %d end1 %d beg2 %d end2 %d\n", j, p-j-1, p, k-p);
							nawiasy[j][i] = nawiasy[j][p-j-1]+nawiasy[p][k-p];
							if(k!=p) nawiasy[j][i]+=1;
							waga[j][i] = waga[j][p-j-1]+waga[p][k-p];
						}
					}
		}
				printf("%d %d\n", wyniki[0][n-1], nawiasy[0][n-1]);
	}
	return 0;
}