#include <stdio.h>
#include <string.h>
#ifdef _DEBUG
#define DEBUG(args ...) printf(args)
#else
#define DEBUG(args ...)
#endif
#define Q 36000

int m;

bool sito[Q];
int primes[Q];
int primes_i=0;

inline int f(int n, int p)
{
	int r = 0;
	while((n > 1) && (n % p == 0))
	{
		n/=p;
		r++;
	}
	return r;
}

void genPrimes(void)
{
	memset(sito, 0, sizeof(sito));
	for(int i=2; i<Q; i++)
	{
		for(int j=2; j<=i; j++)
		{
			if(i*j > Q)
				break;
			sito[i*j] = true;
		}
	}
	//DEBUG("primes: ");
	for(int i=2; i<Q; i++)
	{
		if(!sito[i])
		{
			//DEBUG("%d ", i);
			primes[primes_i++] = i;
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
		int n;
		long long sum = 1;
		scanf("%d", &n);
		for(int i=0; i<primes_i; i++)
		{
			if(n%primes[i] == 0)
			{
				DEBUG("%d dzieli %d\n", primes[i], n);
				long long tmp = primes[i];
				int f_tmp = f(n, primes[i]);
				DEBUG("\tf(%d, %d) = %d\n", n, primes[i], f_tmp);
				for(int j=0; j<f_tmp; j++)
				{
					tmp*=(long long)primes[i];
					DEBUG("%lld ", tmp);
				}
				DEBUG("\n");
				DEBUG("\ttmp = %lld\n", tmp);
				tmp--;
				DEBUG("\ttmp = %lld\n", tmp);
				tmp /= (long long)(primes[i]-1);
				DEBUG("\ttmp = %lld\n", tmp);
				sum *= tmp;
				sum %= m;
			}
			if(primes[i] > n)
				break;
		}
		printf("%lld\n", sum);
	}
	return 0;
}

