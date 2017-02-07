#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>

#include<iostream>
using namespace std;

typedef unsigned long long LL;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

#define PB push_back
#define ALL(X) X.begin(),X.end()
#define rALL(X) X.rbegin(),X.rend()

#define DBG

/*#ifdef DBG
   #define debug(fmt, ...) fprintf(stderr, fmt, ## __VA_ARGS__ )
#else
   #define debug(fmt, ...)
#endif*/

struct N {
   int i;
   int real;
   N() {}
   N(int i1, int real1) {
      i = i1;
      real = real1;
   }
   bool operator<(const N &Q) const {
      return i < Q.i;
   }
};

struct Nlis {
   int hash