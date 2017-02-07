#define DBG
// autor programu: Grzegorz Guspiel 2e
// V LO im. Augusta Witkowskiego w Krakowie

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef DBG
#define REPORT(x) cout<<x<<endl
#else
#define REPORT(x)
#endif

/////////////////////////////////////////////////////////

const int inf=1000000000;
const int maxv=100100;

struct vertex
{
	int d;
	int from;
	int nr;
	vector<vertex*> adj;
	vector<int> w;
	vertex(): d(inf), from(inf){}
	bool operator<(const vertex& b) const {
		if(d==b.d&&from==b.from) return nr<b.nr;
		if(d==b.d) return from<b.from;
		return d<b.d;
	}
};
typedef pair<vertex*, int> pvi;
struct cmp {
	bool operator()(const pvi& a, const pvi& b) const {
		return *b.first<*a.first;
	}
};

int n;
vertex t[maxv];
priority_queue<pvi,vector<pvi>,cmp > q;

void rundijkstra() {
	for(int i=1; i<=n; i++)
		q.push(pvi(&t[i],t[i].d));
	while(!q.empty()) {
		pvi vv = q.top();
		q.pop();
		vertex* v=vv.first;
		if(v->d==inf) break;
		if(vv.second>v->d) continue;
		for(int i=0; i<v->adj.size(); i++)  
			if(v->adj[i]->d>v->d+v->w[i]||v->adj[i]->d==v->d+v->w[i]&&v->from<v->adj[i]->from) {
				v->adj[i]->d=v->d+v->w[i];
				v->adj[i]->from=v->from;
				q.push(pvi(v->adj[i],v->adj[i]->d));
			}
	}
}

int main()
{
	int m,r; scanf("%d%d%d", &n, &m, &r);
	for(int i=0; i<=n; i++) t[i].nr=i;
	for(int i=0; i<r; i++) {
		int a; scanf("%d", &a);
		t[a].from=a;
		t[a].d=0;
	}
	while(m--) {
		int a,b,w;
		scanf("%d%d%d", &a, &b, &w);
		t[a].adj.push_back(&t[b]);
		t[a].w.push_back(w);
		t[b].adj.push_back(&t[a]);
		t[b].w.push_back(w);
	}
	rundijkstra();
	int z; scanf("%d", &z);
	while(z--) {
		int a; scanf("%d", &a);
		if(t[a].d==inf) printf("BRAK\n");
		else printf("%d %d\n", t[a].from, t[a].d);
	}
	return 0;
}

