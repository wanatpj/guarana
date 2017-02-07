#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

#define PB push_back
#define VI vector<int>
#define ALL(X) X.begin(),X.end()

#define PAII pair<int, int>
#define ST first
#define ND second

//#define debug(fmt, ...) fprintf(stderr, fmt, ## __VA_ARGS__ )
#define debug(fmt, ...)

const int MAX = 100005;

VI G[MAX];
vector< PAII > E;

vector< VI > kliki[500];

int n;

int x,a;

VI::iterator jest;
VI temp;

int jestE(int kl, int nr, int v) {
    bool czy;
    REP(i,G[v].size())
    {
       czy = true;
       REP(j,kliki[kl][nr].size()-1)
       {
          jest = lower_bound(ALL(G[kliki[kl][nr][j]]), G[v][i]);
          if(!(jest != G[kliki[kl][nr][j]].end() && *jest == G[v][i])) {
             czy = false;
             break;
          }
       }
       if(czy)
          return G[v][i];
    }
    return 0;
}

void liczdalej() {
    int last, next;
    int ile = 3;
    while(1)
    {
       REP(i,kliki[ile].size())
       {
          last = kliki[ile][i].back();
          if(last == n)
             continue;
          next = jestE(ile, i, last);
          if(next) {
             kliki[ile+1].PB(kliki[ile][i]);
             kliki[ile+1].back().PB(next);
          }
       }
       if(kliki[ile+1].empty())
          break;
       ++ile;
       kliki[ile-1].clear();
    }
    printf("%d\n",ile);
    REP(i,ile)
       printf("%d ",kliki[ile][0][i]);
    printf("\n");
    kliki[ile].clear();
}

PAII odp;

void licz() {
     PAII kr;
     while(!E.empty())
     {
        kr = E[0];
        E.erase(E.begin());
        REP(i,G[kr.ND].size())
        {
           jest = lower_bound(ALL(G[kr.ST]), G[kr.ND][i]);
           if(jest != G[kr.ST].end() && *jest == G[kr.ND][i]) {
              temp.clear();
              temp.PB(kr.ST);
              temp.PB(kr.ND);
              temp.PB(G[kr.ND][i]);
              kliki[3].PB(temp);
              debug("%d %d %d\n",kr.ST,kr.ND,(*jest));
           }
        }
     }
     if(kliki[3].empty()) {
        printf("2\n%d %d\n",odp.ST,odp.ND);
        return;
     }
     liczdalej();
}     

void vanish() {
     FOR(i,1,n)
        G[i].clear();
     kliki[3].clear();
}

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d",&n);
          vanish();
          FOR(i,2,n)
          {
             scanf("%d",&x);
             while(x--)
             {
                scanf("%d",&a);
                G[a].PB(i);
                //S.insert(PAII(a,i));
                //G[i].PB(a);
             }
          }
          odp = PAII(1,G[1][0]);
          FOR(i,1,n)
          {
             REP(j,G[i].size())
                E.PB(PAII(i,G[i][j]));
          }
          REP(i,E.size())
             debug("%d %d\n",E[i].ST,E[i].ND);
          licz();
       }
       return 0;
}
       
