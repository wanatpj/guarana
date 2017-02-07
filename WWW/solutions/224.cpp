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
typedef unsigned long long LL;
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

const int K = 1000;

LL t1[K], t2[K], t3[K];

LL k, m;
void fun(LL n) {
	if (n == 0) {
		REP(i,k) t1[i] = 0;
		t1[0] = 1;
		return;
	}
	fun(n/2);
	if (n&1) {
		REP(i,k-1) t2[i+1] = (t1[i+1]+t1[i])%m;
		t2[0] = t1[0]+t1[k-1];
	}
	else REP(i,k) t2[i] = t1[i];
	REP(i,k) {
		t3[i] = 0;
		REP(j,i+1) t3[i] = (t3[i]+t1[j]*t2[i-j])%m;
		FOR(j,i+1,k) t3[i] = (t3[i]+t1[j]*t2[i+k-j])%m;
	}
	REP(i,k) t1[i] = t3[i];
}
void scase() {
	LL n;
	scanf("%lld%lld%lld",&n,&k,&m);
	fun(n);
	REP(i,k) printf("%lld\n",t1[i]);
}

int main() {
	scase();
	return 0;
}
