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
bool sitko[35000];

int sito(int begin, int end, int ind)
{
	end = (int)(sqrt(end)+1);
	for (int i=begin; i<=end; i++)
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
	long long allSum,to_count;
	for (int i=0; i<1000; i++)
		sitko[i]=false;
	while (c--)
	{
		scanf ("%d", &n);
		allSum = 1;
		to_count=1;
		if (max_n < n)
		{
			ind = sito (max_n, n, ind);
			max_n = n;
		}

		for (int i=0; i<ind;)
		{
			if (n==1)
				break;
			if (n%primes[i] == 0)
			{
				n/=primes[i];
				to_count *= primes[i];
			}
			else
			{
				to_count *= primes[i];
				to_count = (to_count - 1)/(primes[i]-1);
				allSum *= to_count;
				to_count = 1;
				i++;
			}
		}
		if (allSum == 1 && n>1)	
			allSum += n;
		else if (n>1)
			allSum *= ((n*n - 1) / (n-1));
		printf ("%d\n", allSum%m);
	}

return 0;
}
