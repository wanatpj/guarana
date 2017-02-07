/*
 * Suma dzielnikow
 * III Internetowe Mistrzostwa Polski w Programowaniu
 * @author: Aleksandra Rzemyk
 * @shool: V LO Krakow
 */

#include<cstdio>
using namespace std;

int primes[30000];
bool sitko[32001];
int ind;

void sito()
{
	ind = 0;
	for (int i=2; i<=32000; i++)
	{
		if (sitko[i]==0)
		{
		primes[ind] = i;
		ind++;
		for (int j=2*i; j<=32000; j+=i)
			sitko[i] = true;
		}
	}
}

int main ()
{
	int n, c, m;
	scanf ("%d%d", &c, &m);
	long long allSum;
	int to_count,current;
	for (int i=0; i<32001; i++)
		sitko[i]=false;
	sito ();
	while (c--)
	{
		scanf ("%d", &n);
		allSum = 1;
		for (int i = 0; i<ind;i++)
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
		}
		if (n!=1)
			allSum *= (n+1);
		printf ("%lld\n", allSum%m);
	}

return 0;
}
