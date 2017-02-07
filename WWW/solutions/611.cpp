#include <stdio.h>
#include <string.h>
#ifdef _DEBUG
#define DEBUG(args ...) printf(args)
#else
#define DEBUG(args ...)
#endif
#define Q 32000

int m, n;

bool sito[Q];
int primes[Q];
int primes_i=0;

inline int f(int p)
{
	int r = 0;
	while((n > 1) && (n % p == 0))
	{
		n/=p;
		++r;
	}
	return r;
}

void genPrimes(void)
{
	memset(sito, 0, sizeof(sito));
	bool *si = sito+2;
	for(int i=2; i<Q; ++i)
	{
		if(!*si)
		{
			for(int j=2; j*i<=Q; ++j)
				sito[i*j] = true;
		}
		si++;
	}
	int* pr = primes;
	for(int i=2; i<Q; ++i)
	{
		if(!sito[i])
		{
			primes_i++;
			*pr = i;
			pr++;
		}
	}
}

int main(int argc, char* argv[])
{
	int c;
	genPrimes();
	scanf("%d %d", &c, &m);
	while(c--)
	{
		long long sum = 1;
		scanf("%d", &n);
		int lastcostam = n;
		int *pr = primes;
		for(int i=0; i<primes_i; ++i)
		{
			if((*pr)*(*pr) > n)
				break;
			if(n%(*pr) == 0)
			{
				int tmp = *pr;
				int f_tmp = f(tmp);
				//long long lpr = (long long)*pr;
				sum+=tmp;
				for(int j=0; j<f_tmp; j++)
				{
					lastcostam/=*pr;
					tmp*=*pr;
					sum+=tmp;
				}
				//tmp--;
				//tmp /= lpr-1ll;
				//sum *= tmp;
				sum %= m;
			}
			++pr;
		}
		if(lastcostam > 1)
		{
			//long long tmp = lastcostam*lastcostam;
			//tmp--;
			//tmp /= lastcostam-1ll;
			//sum *= tmp;
			sum += lastcostam;
			sum %= m;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
