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
		ind ++;
		for (int j=2*i; j<=end; j+=i)
			sitko[i] = true;
	}
	return ind;
}

int main ()
{
	int n, c, m;
	scanf ("%d%d", &c, &m);
	int max_n=2;
	int ind = 0;
	long long allSum;
	int to_count,current;
	for (int i=0; i<1000; i++)
		sitko[i]=false;
	ind = sito (35000);
	while (c--)
	{
		scanf ("%d", &n);
		allSum = 1;
		to_count=1;
		current = 0;

		for (int i=0; i<ind;)
		{
			if(primes[i]*primes[i]>n || n==1)
				break;
			
			while (n%primes[i] == 0)
			{
				n/=primes[i];
				current += to_count;
				to_count *= primes[i];
			}
			
			current += to_count;
			allSum *= current;
			to_count = 1;
			current = 0;
			i++;
			
		}
		if (n>1)
			allSum *= (n+1);
		
		printf ("%d\n", allSum%m);
	}

return 0;
}
