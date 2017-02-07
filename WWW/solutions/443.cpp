#include <cstdio>
using namespace std;

bool Pierwsze [32001];
int T[10000],wolne=1;

void sito (int limit)
{
	int k;
	for (int i=1;i<=limit;i++)
		Pierwsze[i]=1;
	for (int i=2;i<=limit;i++)
	{
		if (Pierwsze[i])
		{
			k=2;
			while (k*i<=limit)
			{
				Pierwsze[k*i]=0;
				k++;
			}
		}
	}
}

int main()
{
	sito(32000);
	for (int i=2;i<=32000;i++)
		if (Pierwsze[i])
		{
			T[wolne]=i;
			wolne++;
		}
	int C,M,N,a,suma;
	long long wynik;
	scanf ("%d %d",&C, &M);
	while (C>0)
	{
		scanf ("%d",&N);
		wynik=1;
		for (int i=1;T[i]*T[i]<=N;i++)
		{
			a=1;
			suma=1;
			while (N%T[i]==0)
			{
				a=a*T[i];
				suma+=a;
				N=N/T[i];
			}
			wynik*=suma;
		}
		if (N!=1)
			wynik*=(N+1);
		wynik=wynik%M;
		printf ("%lld\n",wynik);
		C--;
	}
	return 0;
}
