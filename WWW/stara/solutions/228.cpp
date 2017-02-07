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

LL gcd(LL a, LL b) { return (!b) ? a : gcd(b,a%b); }

LL fun(LL p, LL q) {
	LL d = gcd(p,q);
	LL nw = p*q/d;
	if (p == q) return p*q;
	if (p > q) return p*q-d*((q*(q/d-1))/2);
	if (p < q) return d*(p*(p/d+1))/2;
}
LL brut(LL p, LL q) {
	LL c(0), pc(0), qc(0);
	REP(i,p*q) {
		if (c == 0) pc++; else qc++;
		if ((i+1)%p == 0 && (i+1)%q == 0) continue;
		if ((i+1)%p == 0) c = 1;
		if ((i+1)%q == 0) c = 0;
	}
	LL d = gcd(pc,qc);
	return pc;
}
int main() {
	int z;
	scanf("%d",&z);
	while (z--) {
		LL p, q;
		scanf("%lld %lld",&p,&q);
		LL a = fun(p,q);
		LL d = gcd(a,p*q-a);
		printf("%lld %lld\n",a/d,(p*q-a)/d);
	}
	return 0;
}
