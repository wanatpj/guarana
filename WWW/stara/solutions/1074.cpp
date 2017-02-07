#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define FOR(i,p,k) for(int (i) = (p);(i)<=(k);(i)++)
#define FORD(i,p,k) for(int (i) = (p);(i)>=(k);(i)--)
#define VAR(i,u) __typeof(u) i = (u)
#define FOREACH(i,u) for(VAR(i,(u).begin());(i)!=(u).end();(i)++)
#define INF 1000000000
const long long INFTY = 1000000000000000001LL;

int n, m, pot, il;
long long k;
int kol[100001], s[100001], t[100001], z[100001], q[100001];
vector <int> l[100001];

long long tr[300001];
void init()
{
	pot=1;
	while(pot<m)
		pot*=2;
	REP(i,2*pot+1)
		tr[i]=0;
}

void add(int u, int p, int k, int a, int b, long long v)
{
//	printf("%d %d %d %d %d %d\n", u, p, k, a, b, v);
	if(p<=a && b<=k)
	{
		tr[u]+=v;
		if(tr[u]>=INFTY)
			tr[u]=INFTY;
		return;
	}
	if(k>=(a+b)/2+1)
		add(2*u+1,p,k,(a+b)/2+1,b,v);
	if(p<=(a+b)/2)
		add(2*u,p,k,a,(a+b)/2,v);
}

long long find(int u)
{
	u+=pot;
	long long wynik=0;
	while(u>0)
	{
		wynik+=tr[u];
		if(wynik>=INFTY)
			return INFTY;
		u/=2;
	}
	return wynik;
}

bool por(int a, int b)
{
	return s[a]>s[b];
}

bool por2(int a, int b)
{
	if(t[a]==t[b])
		return t[a]<t[b];
	return s[a]<s[b];
}

int main()
{
	int T, poz, ret;
	long long licz;
	scanf("%d", &T);
	while(T>0)
	{
		T--;
		scanf("%d %d %lld", &n, &m, &k);
		REP(i,n)
		{
			scanf("%d", &kol[i]);
			z[i]=kol[i];
		}
		sort(z,z+n);
		REP(i,n)
		{
			q[lower_bound(z,z+n,kol[i])-z]=i;
		}
		REP(i,m)
			scanf("%d", &t[i]);
		init();
		poz=0;
		REP(i,m)
		{
			ret=lower_bound(z,z+n,t[i])-z;
			if(ret<n && z[ret]==t[i])
			{
				s[poz]=q[ret];
				t[poz]=t[i];
				poz++;
			}
		}
		m=poz;
		il=0;
		REP(i,m)
		{
			ret=lower_bound(q,q+il,s[i])-q;
			if(ret==il)
				l[ret].clear();
			l[ret].PB(i);
			q[ret]=s[i];
			z[i]=ret;
			if(ret==il)
				il++;
		}
		licz=0;
		REP(i,il)
		{
			kol[i]=licz;
			FOREACH(it,l[i])
				q[*it]=licz+it-l[i].begin();
			licz+=l[i].size();
		}
		kol[il]=licz;
		if(m==0)
		{
			printf("0\n-1\n");
			continue;
		}
		FOREACH(it,l[il-1])
			add(1,q[*it],q[*it],0,pot-1,1);
		FORD(i,m-1,0)
		{
			long long ret=find(q[i]);
			if(z[i]!=0)
			{
				int a=upper_bound(ALL(l[z[i]-1]),i,por)-l[z[i]-1].begin();
				poz=lower_bound(ALL(l[z[i]]),i)-l[z[i]].begin();
				if(poz>0 && s[l[z[i]][poz-1]]==s[i])
					a=max(a,lower_bound(ALL(l[z[i]]),l[z[i]][poz])-l[z[i]].begin());
				int b=lower_bound(ALL(l[z[i]-1]),i)-l[z[i]-1].begin()-1;
				if(b>=a)
					add(1,q[l[z[i]-1][a]],q[l[z[i]-1][b]],0,pot-1,ret);
			}
		}
		int last=-1, e=-1;
		k--;
		bool ok;
		printf("%d\n", il);
		REP(i,il)
		{
			poz=l[i].size();
			REP(j,poz)
				kol[j]=l[i][j];
			sort(kol,kol+poz,por2);
			licz=0;
			ok=0;
			REP(j,poz)
			{
				if(kol[j]>last && s[kol[j]]>e)
				{
					/*
					int ret=lower_bound(ALL(l[i]),kol[j])-l[i].begin()-1;
					if(ret>=0 && s[ret]==s[kol[j]] && ret>last)
					continue;*/
					if(j>0 && t[kol[j-1]]==t[kol[j]])
						continue;
					if(licz+find(q[kol[j]])>k)
					{
						printf("%d", t[kol[j]]);
						if(i<il-1)
							printf(" ");
						last=kol[j];
						e=s[kol[j]];
						k-=licz;
						ok=1;
						break;
					}
					else
						licz+=find(q[kol[j]]);
				}
			}
			if(!ok)
			{
				printf("-1");
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
