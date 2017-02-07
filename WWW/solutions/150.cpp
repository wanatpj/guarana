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
	vertex(): d(inf), from(-1){}
};
struct miniv {
	int d, from,nr;
	miniv() {}
	miniv(int id, int ifrom, int inr): d(id), from(ifrom), nr(inr) {}
	bool operator<(const miniv& a) const {
		if(d==a.d&&from==a.from) return nr>a.nr;
		if(d==a.d) return from>a.from;
		return d>a.d;
	}
};

int n;
vertex t[maxv];
priority_queue<miniv> q;

void rundijkstra() {
	for(int i=1; i<=n; i++)
		q.push(miniv(t[i].d,t[i].from,i));
	while(!q.empty()) {
		miniv vv = q.top();
		q.pop();
		vertex* v=&t[vv.nr];
		if(vv.d==inf) break;
		if(miniv(v->d,v->from,v->nr)<vv) continue;
		for(int i=0; i<v->adj.size(); i++)  
			if(v->adj[i]->d>v->d+v->w[i]||v->adj[i]->d==v->d+v->w[i]&&v->from<v->adj[i]->from) {
				v->adj[i]->d=v->d+v->w[i];
				v->adj[i]->from=v->from;
				q.push(miniv(v->adj[i]->d,v->adj[i]->from,v->adj[i]->nr));
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
