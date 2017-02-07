/*
 * Suma dzielnikow
 * III Internetowe Mistrzostwa Polski w Programowaniu
 * @author: Aleksandra Rzemyk
 * @shool: V LO Krakow
 */

#include<cstdio>
#include<cmath>
using namespace std;

int primes[35000];
bool sitko[35001];

int sito(int end)
{
	int ind = 0;
	for (int i=2; i<=end; i++)
	{
		if (sitko[i]==true)
			continue;
		primes[ind] = i;
		ind++;
		for (int j=2*i; j<=end; j+=i)
			sitko[j] = true;
	}
	return ind;
}

int main ()
{
	int n, c, m;
	scanf ("%d%d", &c, &m);
	long long allSum;
	int to_count,current;
	for (int i=0; i<35001; i++)
		sitko[i]=false;
	int ind = sito (35000);
	int i;
	while (c--)
	{
		scanf ("%d", &n);
		allSum = 1;
		i=0;
		while ( i<ind)
		{
			if (n==1)
				break;
			if(primes[i]*primes[i]>n)
				break;
			
			to_count = 1;
			current = 1;
			
			while (n%primes[i] == 0)
			{
				n/=primes[i];
				to_count *= primes[i];
				current += to_count;
			}
			if(to_count!=1)
				allSum *= current;
			++i;
			
		}
		if (n!=1)
			allSum *= (n+1);
		
		printf ("%lld\n", allSum%m);
	}

return 0;
}
