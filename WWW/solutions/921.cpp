#include <cstdio>
#include <algorithm>
using namespace std;

int D,T[10001],N,wynik;

int main()
{
	scanf ("%d",&D);
	while (D>0)
	{
		wynik=0;
		scanf ("%d",&N);
		for (int i=1;i<=N;i++)
			scanf ("%d",&T[i]);
		sort (T+1,T+N+1);
		while (N>3)
		{
			wynik+=min(T[N]+T[2]+T[1]+T[2],T[1]*2+T[N]+T[N-1]);
			N-=2;
		}
		if (N==2)
			wynik+=T[2];
		else
			wynik+=T[1]+T[2]+T[3];
		printf ("%d\n",wynik);
		D--;
	}
	return 0;
}
