#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct kr
{
    int to,w;
};
struct edge
{
    int to,w,from;
};
struct cmp
{
    bool operator()(const edge & a, const edge & b)
    {
	if(a.w>b.w) return true;
	else if(a.w==b.w)
	{
	    if(a.from>b.from) return true;
	    return false;
	}
	return false;
    }
};

const int INF=2000000000;
const int MAXN=100005;
int D[MAXN], FROM[MAXN];
priority_queue<edge, vector<edge>, cmp> Q;
vector<kr> G[MAXN];
vector<int> V;
int n,m,r,a,b,c;

int main()
{
    edge tmp, tmp2;
    kr kraw;
    scanf("%d%d%d", &n,&m,&r);
    for(int i=0; i<=n; i++) {D[i]=INF; FROM[i]=INF;}
    while(r--)
    {
	scanf("%d", &a);
	V.push_back(a);
    }
    while(m--)
    {
	scanf("%d%d%d", &a,&b,&kraw.w);
	kraw.to=b;
	G[a].push_back(kraw);
	kraw.to=a;
	G[b].push_back(kraw);
    }
    for(int i=0; i<V.size(); i++)
    {
	a=V[i];
	//D[a]=0;
	//FROM[a]=a;
	tmp.to=a;
	tmp.w=0;
	tmp.from=a;
	Q.push(tmp);
    }
    while(!Q.empty())
    {
	tmp=Q.top();
	Q.pop();
	a=tmp.to;
	if(D[a]!=INF) continue;
	D[a]=tmp.w;
	FROM[a]=tmp.from;
	for(int i=0; i<G[a].size(); i++)
	{
	    b=G[a][i].to;
	    if(D[b]==INF)
	    {
		tmp2.to=b;
		tmp2.w=D[a]+G[a][i].w;
		tmp2.from=FROM[a];
		Q.push(tmp2);
	    }
	}
    }
    scanf("%d", &a);
    while(a--)
    {
	scanf("%d", &b);
	if(D[b]!=INF)
	    printf("%d %d\n", FROM[b], D[b]);
	else printf("BRAK\n");
    }
return 0;
}
