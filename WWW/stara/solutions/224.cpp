#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <sstream>
#include <bitset>
using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;

const int INF = 1000*1000*1000+1;
#define FOR(x,b,e) for (int x = (b); x < (e); ++x)
#define FORD(x,b,e) for (int x = (b); x >= (e); --x)
#define REP(x,n) for (int x = 0; x < (n); ++x)
#define VAR(v,n) __typeof(n) v = (n)
#define ALL(c) c.begin(), c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for (VAR(i,c.begin()); i != c.end(); ++i)
#define PB push_back
#define ST first
#define ND second

const int N = 100000;
int n;

struct MS {
	int ST;
	list<MS>::iterator ND;
	MS(const int & nST = 0) : ST(nST) {}
};
typedef list<MS>::iterator LMT;
vector<list<MS> > g,gc;

int r;
VI l, vis, lc, visc;
inline int remove_edge(int u, LMT it) { int v = it->ST; g[v].erase(it->ND); g[u].erase(it); return v; }
queue<int> q1, q2, q1c, q2c;
inline void check(int v) {
	if (l[v] >= 2) q1.push(v);
	else if (SIZE(g[v]) == 0) vis[v] = 1;
	else if (SIZE(g[v]) >= 2) return;
	else if (l[v] == 1) q2.push(v);
	else {
		vis[v] = 1;
		int u = remove_edge(v,g[v].begin());
		l[u]++;
		check(u);
	}
}
inline void print(vector<list<MS> > g) {
	REP(i,n) { cout << i+1 << ": "; FOREACH(it,g[i]) cout << it->ST+1 << ' '; cout << endl; }
	cout << endl;
}
inline void cut() {
	REP(u,n) if (SIZE(g[u]) == 1 && l[u] == 0) {
		vis[u] = 1;
		int v = remove_edge(u,g[u].begin());
		l[v]++;
		check(v);
	}
	while (!q1.empty() || !q2.empty()) { // jak z priorytetami?
//		print(g);
//		REP(i,n) cout << l[i] << ' '; cout << endl;
		if (!q1.empty()) {
			int u = q1.front();
//			cout << "U1 " << u << endl;
			q1.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			++r;
			while (SIZE(g[u]) != 0) {
				int v = remove_edge(u,g[u].begin());
				check(v);
			}
		}
		else {
			int u = q2.front();
//			cout << "U2 " << u << endl;
			q2.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			if (SIZE(g[u]) == 0) continue;
			int v = remove_edge(u,g[u].begin());
			++r;
			vis[v] = 1;
			while (SIZE(g[v]) != 0) {
				int x = remove_edge(v,g[v].begin());
				check(x);
			}
		}
	}
}
vector<PII> edg;
void construct_graph() {
	REP(i,SIZE(edg)) {
		int u = edg[i].ST;
		int v = edg[i].ND;
		g[u].push_front(MS());
		g[u].begin()->ST = v;
		g[v].push_front(MS());
		g[v].begin()->ST = u;
		g[v].begin()->ND = g[u].begin();
		g[u].begin()->ND = g[v].begin();
	}
}

int main() {
	scanf("%d",&n);
	g.resize(n);
	edg.resize(n);
	REP(i,n) { 
		int u, v;
		scanf("%d%d",&u,&v); --u; --v;
		edg[i] = PII(u,v);
	}
	construct_graph();
	r = 0;
	l.resize(n); vis.resize(n);
	cut();
//	REP(i,n) cout << l[i] << ' '; cout << endl;
//	cout << r << endl;
//	print(g);	
	int c = 0;
	REP(i,n) c += !vis[i];
//	cout << c << endl;
	if (c == 0) { printf("%d\n",r); return 0; }
	int i = 0;
	for(; i < n; ++i) if (!vis[i] && l[i] > 0) break;
	if (i == n) { printf("%d\n",r+c/3); return 0; }
	if (c == 3) { printf("%d\n",r+1); return 0; }
	int rc = r;
	gc = g; q1c = q1; q2c = q2; visc = vis; lc = l;
	int u = i;
	int v1 = g[u].begin()->ST;
	int v2 = (++g[u].begin())->ST;
//	cout << SIZE(g[u]) << endl;
//	cout << u << ' ' << v1 << ' ' << v2 << endl;
	while (SIZE(g[u]) != 0) {
		int x = remove_edge(u,g[u].begin());
	}
	int x = remove_edge(v1,g[v1].begin());
	check(x);
	check(v2);
	vis[v1] = vis[u] = 1;
//	REP(i,n) { cout << i << ": "; FOREACH(it,g[i]) cout << it->ST << ' '; cout << endl; }
	cut();
	int r1 = r;
	q1 = q1c; q2 = q2c; vis = visc; l = lc; r = rc;
	edg.clear();
	g.clear();
	g.resize(n);
	REP(i,n) FOREACH(it,gc[i]) if (i < it->ST) edg.PB(PII(i,it->ST));
	construct_graph();
//	REP(i,n) { cout << i << ": "; FOREACH(it,g[i]) cout << it->ST << ' '; cout << endl; }
	while (SIZE(g[u]) != 0) {
		int x = remove_edge(u,g[u].begin());
	}
	x = remove_edge(v2,g[v2].begin());
	check(x);
	check(v1);
	vis[v2] = vis[u] = 1;
	cut();
	int r2 = r;
//	cout << "R12 "<< r1 << ' ' << r2 << endl;
	printf("%d\n",max(r1,r2)+1);
	return 0;
}
