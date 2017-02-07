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

#define DBGa

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
const int MAX = 100010;

set<N, cmp> SA;
set<N, cmp>::iterator jest;

int tabN[MAX];
int tabM[MAX];
vector<Nlis> LISY[MAX];
vector<Nlis>::iterator mn, wi;

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

bool cmpT(const Nlis &Q, const Nlis &W) {
     return Q.t < W.t;
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

vector<int> W;

void licz() {
     lis();
     /*REP(i,len)
     {
        debug("%d: ",i);
        REP(j,LISY[i].size())
           debug("%d(%d) ",LISY[i][j].hash, LISY[i][j].t);
        debug("\n");
     }*/
     
     REP(i,LISY[len-1].size())
        LISY[len-1][i].ile = 1;
     
     LL temp;
     int wsk;
     FORD(i,(len-2),0)
     {
        REP(j,LISY[i].size())
        {
           LISY[i][j].ile = 0;
           mn = upper_bound(ALL(LISY[i+1]), LISY[i][j], cmpT);
           while(mn != LISY[i+1].end() && (*mn).hash > LISY[i][j].hash)
           {
              LISY[i][j].ile += (*mn).ile;
              ++mn;
           }
        }
     }
     
     /*REP(i,len)
     {
        debug("%d: ",i);
        REP(j,LISY[i].size())
           debug("%d(%d) ",LISY[i][j].hash, LISY[i][j].ile);
        debug("\n");
     }*/
     
     bool czy = false;
     LL ileIchJest = 0;
     REP(i,LISY[0].size())
     {
        ileIchJest += LISY[0][i].ile;
        //debug("%lld\n",LISY[0][i].ile);
        if(ileIchJest >= k) {
           czy = true;
           break;
        }
     }
     if(!czy) {
        printf("-1\n");
        return;
     }
     
     int gdzieJestem = 0;
     int lastHash = -1;
     REP(i,len)
     {
        sort(ALL(LISY[i]), cmpL);
        REP(j,LISY[i].size())
        {
           if(LISY[i][j].t < gdzieJestem || LISY[i][j].hash < lastHash)
              continue;
           if(k > LISY[i][j].ile) {
              k -= LISY[i][j].ile;
              continue;
           }
           //W.PB(tabN[LISY[i][j].hash]);//
           printf("%d ",tabN[LISY[i][j].hash]);
           gdzieJestem = LISY[i][j].t;
           lastHash = LISY[i][j].hash;
           break;
        }
     }
     /*if(k == 0)
        REP(i,W.size())
           printf("%d ",W[i]);
     else
        printf("-1");*/
     printf("\n");
}

void vanish() {
     REP(i,len)
        LISY[i].clear();
     ileM = len = t = 0;
     SA.clear();
}

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d %d %lld",&n,&m,&k);
          vanish();
          REP(i,n)
          {
             scanf("%d",&x);
             tabN[i] = x;
             SA.insert(N(i, x));
          }
          REP(i,m)
          {
             scanf("%d",&x);
             jest = SA.find(N(i, x));
             if(jest != SA.end())
                tabM[ileM++] = (*jest).i;
          }
          if(ileM == 0) {
             printf("0\n-1\n");
             continue;
          }
          licz();
       }
       return 0;
}
       
