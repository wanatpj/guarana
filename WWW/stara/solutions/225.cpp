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

LL a,b,c,d,p;
LL a1,b1,c1,d1;
LL a2,b2,c2,d2;

inline void compose(LL a3, LL b3, LL c3, LL d3) {
	a2 = (a1*a3+b1*c3)%p;
	b2 = (a1*b3+b1*d3)%p;
	c2 = (c1*a3+d1*c3)%p;
	d2 = (c1*b3+d1*d3)%p;
}
void fun(LL n) {
	if (n == 0) { a1 = d1 = 1; b1 = c1 = 0; return; }
	fun(n/2);
	if (n&1) compose(a,b,c,d);
	else { a2 = a1; b2 = b1; c2 = c1; d2 = d1; }
	compose(a2,b2,c2,d2);
	a1 = a2; b1 = b2; c1 = c2; d1 = d2;
}
LL mexp(LL a, LL n) {
	LL x = a;
	n--;
	while (n) {
		if (n&1) a = a*x%p;
		x = x*x%p;
		n /= 2;
	}
	return a;
}
int main() {
	int k;
	scanf("%d",&k);
	while (k--) {
		LL x, n;
		scanf("%lld%lld%lld%lld%lld%lld%lld",&p,&a,&b,&c,&d,&x,&n);
		fun(n);
		LL l = (a1*x+b1)%p;
		LL k = (c1*x+d1)%p;
		if (k == 0) printf("-1\n");
		else printf("%lld\n",l*mexp(k,p-2)%p);
	}
	return 0;
}
