#include <cstdio>
#include <algorithm>

using namespace std;

#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define FOR(i,p,k) for(int (i) = (p);(i) <= (k);(i)++)

#define INF 1000000000

int pi[30000];
bool sito[32001];
int il;
void f()
{
	il=0;
	REP(i,32001)
	{
		sito[i]=0;
	}
	for(int i = 2;i<=32000;i++)
	{
		if(sito[i]==0)
		{
			pi[il]=i;
			il++;
			for(int j = 2*i;j<=32000;j+=i)
			{
				sito[j]=1;
			}
		}
	}
}

int main()
{
	int c, M, n, m, r, s;
	long long w;
	f();
	random_shuffle(pi,pi+il);
	scanf("%d %d", &c, &M);
	while(c>0)
	{
		c--;
		scanf("%d", &n);
		m=n;
		w=1;
		REP(i,il)
		{
			if(m==1)
				break;
			r=1;
			s=1;
			while(m%pi[i]==0)
			{
				m/=pi[i];
				r*=pi[i];
				s+=r;
			}
			if(r!=1)
				w*=s;
		}
		if(m!=1)
			w*=m+1;
		w%=M;
		printf("%lld\n", w);
	}
	return 0;
}
