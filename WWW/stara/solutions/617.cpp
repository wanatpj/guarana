#include <stdio.h>
#include <string.h>
#ifdef _DEBUG
#define DEBUG(args ...) printf(args)
#else
#define DEBUG(args ...)
#endif
#define Q 36000

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
	//DEBUG("primes: ");
	int* pr = primes;
	for(int i=2; i<Q; ++i)
	{
		if(!sito[i])
		{
			//DEBUG("%d ", i);
			primes_i++;
			*pr = i;
			pr++;
		}
	}
	//DEBUG("\n");
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
		long long lastcostam = (long long)n;
		int *pr = primes;
		for(int i=0; i<primes_i; ++i)
		{
			if((*pr)*(*pr) > n)
			{
				DEBUG("primes[%d] = %d - BREAK;\n", i, primes[i]);
				break;
			}
			//DEBUG("primes[%d] = %d; n mod %d=%d\n", i, primes[i], primes[i], n%primes[i]);
			if(n%primes[i] == 0)
			{
				DEBUG("%d dzieli %d\n", *pr, n);
				long long tmp = *pr;
				int f_tmp = f(tmp);
				DEBUG("\tf(%d, %d) = %d\n", n, tmp, f_tmp);
				long long lpr = (long long)*pr;
				for(int j=0; j<f_tmp; j++)
				{
					lastcostam/=lpr;
					tmp*=lpr;
					DEBUG("%lld ", tmp);
				}
				DEBUG("\n");
				DEBUG("\ttmp = %lld\n", tmp);
				tmp--;
				DEBUG("\ttmp = %lld\n", tmp);
				tmp /= lpr-1ll;
				DEBUG("\ttmp = %lld\n", tmp);
				sum *= tmp;
				sum %= m;
			}
			pr++;
		}
		if(lastcostam > 1)
		{
			long long tmp = lastcostam*lastcostam;
			tmp--;
			tmp /= lastcostam-1ll;
			sum *= tmp;
			sum %= m;
		}
		printf("%lld\n", sum);
	}
	return 0;
}

