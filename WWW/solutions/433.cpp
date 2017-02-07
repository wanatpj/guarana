#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define FOR(i,p,k) for(int (i) = (p);(i) <= (k);(i)++)

#define INF 1000000000

int pi[30000], sito[40001], il;
void f()
{
	il=0;
	REP(i,40001)
	{
		sito[i]=0;
	}
	for(int i = 2;i<=40000;i++)
	{
		if(sito[i]==0)
		{
			pi[il]=i;
			il++;
			for(int j = 2*i;j<=40000;j+=i)
			{
				sito[j]=1;
			}
		}
	}
}

int main()
{
	int c, M, n;
	scanf("%d %d", &c, &M);
	f();
	while(c>0)
	{
		c--;
		scanf("%d", &n);
		int m=n, r;
		long long w=1;
		REP(i,il)
		{
			if(m==1)
				break;
			r=pi[i];
			while(m%pi[i]==0)
			{
				m/=pi[i];
				r*=pi[i];
			}
			if(r!=pi[i])
			{
				w*=(r-1)/(pi[i]-1);
				w%=M;
			}
		}
		if(m!=1)
		{
			w*=m+1;
			w%=M;
		}
		printf("%lld\n", w);
	}
	return 0;
}
