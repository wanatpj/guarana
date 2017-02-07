#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PB push_back
#define PI pair<int,int>
#define st first
#define nd second
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,((c).begin()));i!=(c).end();++i)
#define FOR(i,n) for(int i = 0;i<n;i++)

struct e{
	int v, s, c;
	e(){}
	e(int a, int b, int r)
		{v=a;s=b;c=r;}
};

int n, m, r;
vector <PI> G[100001];
int dist[100001], src[100001];

bool operator<(const e & a, const e & b)
{
	if(a.c!=b.c)
		return a.c>b.c;
	return a.s>b.s;
}

priority_queue <e> Q;

void dfs()
{
	for(int i = 0;i<=n;i++)
		dist[i]=-1;
	dist[0]=0;
	while(!Q.empty())
	{
		int u = Q.top().v;
		if(dist[u]!=-1)
		{
			Q.pop();
			continue;
		}
		dist[u]=Q.top().c;
		src[u]=Q.top().s;
		Q.pop();
		FOREACH(it,G[u])
		{
			if(dist[it->st]==-1)
				Q.push(e(it->st,src[u],dist[u]+it->nd));
		}
	}
}

int main()
{
	int u, v, c, il;
	scanf("%d %d %d", &n, &m, &r);
	for(int i = 0;i<r;i++)
	{
		scanf("%d", &u);
		Q.push(e(u,u,0));
	}
	for(int i = 0;i<m;i++)
	{
		scanf("%d %d %d", &u, &v, &c);
		G[u].PB(PI(v,c));
		G[v].PB(PI(u,c));
	}
	dfs();
	scanf("%d", &il);
	FOR(i,il)
	{
		scanf("%d", &u);
		if(dist[u]!=-1)
			printf("%d %d\n", src[u], dist[u]);
		else
			printf("BRAK\n");
	}
	return 0;
}
