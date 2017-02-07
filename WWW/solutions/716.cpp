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
//	int k;
	int tempNaw;
	int tempWyn;
	int actWyn;
	int actNaw;
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
		for(int i=1; i<n; i++) // dla kazdej dlugosci
		{
			for(int j=0; j<n-i; j++) // wybierz poczatek 
			{
//				k=i+j;
				waga[j][i] = waga[j][0]+waga[j+1][i-1];
				wyniki[j][i]=  wyniki[j][0]+/*waga[j][p-j-1]+waga[p][k-p]*/+wyniki[j+1][i-1]+waga[j][i];
				nawiasy[j][i] = nawiasy[j][0]+nawiasy[j+1][i-1]; // potencjalnie nowa liczba nawiasow
				if(i!=1) nawiasy[j][i]+=1;

				//				if(i+j<n)
				for(int p=j+2; p <= j+i; p++) // mozliwy 'srodek', srodek juz nalezy do part 2
				{
					//						if(p==j+1) waga[j][i] = waga[j][p-j-1]+waga[p][k-p];
					tempNaw = nawiasy[j][p-j-1]+nawiasy[p][i+j-p]; // potencjalnie nowa liczba nawiasow
					if(i+j!=p) tempNaw+=1;
					tempWyn = wyniki[j][p-j-1]+/*waga[j][p-j-1]+waga[p][k-p]*/+wyniki[p][i+j-p]+waga[j][i]; // potencjalny wynik

					//						actWyn = wyniki[j][i];
					//						actNaw = nawiasy[j][i];

					if(wyniki[j][i] > tempWyn || (wyniki[j][i] == tempWyn && nawiasy[j][i]>tempNaw)  )
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