#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
#define PB push_back
const int MAXN = 40000;
const int dbg=0;
const int dbgSito=0;
//oblicza a^x
inline LL power(LL a,LL x)
{
	LL res=1;
	while(x!=0)
	{
		if(x&1)res*=a;
		x>>=1;
		a*=a;
	}
	return res;
}
VI pri;
LL m;
void sito()
{
	if(dbgSito)printf("sito()\n");
	pri.clear();
	bool p[MAXN];
	for(int i=0;i<MAXN;i++)
		p[i]=1;
	if(dbgSito)printf("sito() init:ok\n");
	for(LL i=2;i<MAXN;i++)
		if(p[i])
		{
			if(dbgSito)printf("sito() i:%lld\n",i);
			for(LL j=i*i;j<MAXN;j+=i)
				p[j]=0;
			pri.PB(int(i));
		}
	if(dbgSito)
	{
		printf("pri:[");
		for(int i=0;i<pri.size();i++)
			printf("%d ",pri[i]);
		printf("]\n");
	}
}

LL sumaDzielnikow(LL n)
{
	LL result=1;
	int alpha;
	for(int i=0;i<pri.size();i++)
	{
		if(dbg)printf("sumaDzielnikow() pri[i]:%d n:%lld m:%lld\n",pri[i],n,m);
		alpha=0;
		while(n%pri[i]==0)
		{
			alpha++;
			n/=pri[i];
		}
		if(alpha==0)continue;
		if(dbg)printf("power(%d,%d):%lld\n",pri[i],alpha+1,power(pri[i],alpha+1));
		result*=((power(pri[i],alpha+1)-1)/(pri[i]-1))%m;
		result%=m;
		if(n==1)break;
	}
	if(n!=1)
		result*=(n+1);
	result%=m;
	return result;
}

int main()
{
	sito();
	int c;
	LL n;
	scanf("%d%lld",&c,&m);
	while(c--)
	{
		scanf("%lld",&n);
		printf("%lld\n",sumaDzielnikow(n));
	}
	return 0;
}

