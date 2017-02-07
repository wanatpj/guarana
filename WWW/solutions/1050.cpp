#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

typedef long long LL;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

#define PB push_back
#define ALL(X) X.begin(),X.end()

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
   int hash;
   int t;
   LL ile;
   Nlis() {}
   Nlis(int hash1, int t1) {
      hash = hash1;
      t = t1;
   }
   Nlis(int hash1, int t1, LL ile1) {
      hash = hash1;
      t = t1;
      ile = ile1;
   }
   bool operator<(const Nlis &Q) const {
      return hash < Q.hash;
   }
};

struct cmp {
   bool operator()(const N &Q, const N &W) {
      return Q.real < W.real;
   }
};
const int MAX = 100000;

set<N, cmp> SA;
set<N, cmp>::iterator jest;

int tabN[MAX];
int tabM[MAX];
vector<Nlis> LISY[MAX];
int *jestLis;

int LIS[MAX];
int len;
int t;

int n, m;
LL k;
int ileM;
int x;

bool cmpL(const Nlis &Q, const Nlis &W) {
     return tabN[Q.hash] < tabN[W.hash];
}

inline void lis() {
     LIS[len++] = tabM[0];
     LISY[0].PB(Nlis(tabM[0], ++t));
     FOR(i,1,(ileM-1))
     {
        if(LIS[len-1] < tabM[i]) {
           LISY[len].PB(Nlis(tabM[i], ++t));
           LIS[len++] = tabM[i];
        }
        else {
           jestLis = lower_bound(LIS, LIS+len, tabM[i]);
           if((*jestLis) != tabM[i]) {
              LIS[jestLis-LIS] = tabM[i];
              LISY[jestLis-LIS].PB(Nlis(tabM[i], ++t));
           }
        }
     }
     printf("%d\n",len);
}

void licz() {
     lis();
     /*REP(i,len)
     {
        debug("%d: ",i);
        REP(j,LISY[i].size())
           debug("%d(%d) ",LISY[i][j].hash, LISY[i][j].t);
        debug("\n");
 