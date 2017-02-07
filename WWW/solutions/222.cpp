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

const int INF = 2*1000*1000*1000+1;
const int NIL = -1;
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
int rs[N], d[N], p[N];
vector<VI> g;
vector<VI> w;
int n, m, r;

struct DS {
	int d, i;
	DS(int ni = 0, int nd = 0) : i(ni), d(nd) {}
	bool operator< (const DS & s) const { return (d > s.d) || (d == s.d && i > s.i); }
};

void dijkstra() {
	priority_queue<DS> q;
	REP(i,n) { d[i] = INF; p[i] = NIL; }
	REP(i,r) { d[rs[i]] = 0; p[rs[i]] = rs[i];  q.push(DS(rs[i],0)); }
	while (!q.empty()) {
		DS s = q.top();
		q.pop();
		if (s.d != d[s.i]) continue;
		int u = s.i;
		REP(j,SIZE(g[u])) {
			int v = g[u][j];
			if (d[u] + w[u][j] < d[v] || (d[u] + w[u][j] == d[v] && p[u] < p[v])) {
				d[v] = d[u] + w[u][j];
				p[v] = p[u];
				q.push(DS(v,d[v]));
			}
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&r);
	REP(i,r) { scanf("%d",&rs[i]); rs[i]--; }
	g.resize(n); w.resize(n);
	REP(i,m) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		g[a-1].PB(b-1); w[a-1].PB(c);
		g[b-1].PB(a-1); w[b-1].PB(c);
	}
	dijkstra();
	int q;
	scanf("%d",&q);
	REP(i,q) {
		int v;
		scanf("%d",&v); --v;
		if (d[v] == INF) printf("BRAK\n");
		else printf("%d %d\n",p[v]+1,d[v]);
	}

	return 0;
}
