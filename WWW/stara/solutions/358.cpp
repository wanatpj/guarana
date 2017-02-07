#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

const int MAX = 10000;
const int MAXM = 20000;

struct zez {
   int kto, kogo;
   bool winny;
   zez() {}
   zez(int kto1, int kogo1, bool winny1) {
      kto = kto1;
      kogo = kogo1;
      winny = winny1;
   }
};

zez K[MAXM+1];

int kogo[MAX+1];
set<int> kogonie[MAX+1];
bool klamca[MAX+1];
int naniego[MAX+1];
int naniegonie[MAX+1];

int n,m;

int a,b;
char c;

int ile;

void licz() {
     int ile = 0;
     FOR(i,1,n)
     {
        if(kogonie[i].size() == n-1 || kogonie[i].find(kogo[i]) != kogonie[i].end())
           klamca[i] = true;
        //printf("%d %d\n",i,klamca[i]);
        if(!klamca[i]) {
           ++naniego[kogo[i]];
           for(set<int>::iterator it=kogonie[i].begin();it!=kogonie[i].end();++it)
              ++naniegonie[(*it)];
        }
     }
     FOR(i,1,n)
        if(!klamca[i])
           if(kogo[i])
              ++ile;
     // FOR(i,1,n) printf("%d %d %d\n",i,naniego[i],naniegonie[i]);
     int mi = 1000000000;
     FOR(i,1,n)
     {
        mi = min(mi, naniegonie[i] + (ile - naniego[i]));
     }
     FOR(i,1,n)
        if(naniegonie[i] + ile - naniego[i] == mi)
           printf("%d ",i);
     printf("\n");
}

void vanish() {
     FOR(i,1,n)
     {
        naniego[i] = naniegonie[i] = kogo[i] = klamca[i] = 0;
        kogonie[i].clear();
     }
     ile = 0;
}

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d %d",&n,&m);
          vanish();
          FOR(i,1,m)
          {
             scanf("%d %c %d",&a, &c, &b);
             if(c == 'W') {
                if(kogo[a] && kogo[a] != b) {
                   klamca[a] = true;
                }
                else {
                   kogo[a] = b;
                }
                K[i] = zez(a, b, true);
             }
             else if(c == 'P') {
                if(K[b].winny) {
                   if(kogo[a] && kogo[a] != K[b].kogo)
                      klamca[a] = true;
                   else
                      kogo[a] = K[b].kogo;
                }
                else {
                   if(kogo[a] == K[b].kogo)
                      klamca[a] = true;
                   else
                      kogonie[a].insert(K[b].kogo);
                }
                K[i] = zez(a, K[b].kogo, K[b].winny);
             }
             else if(c == 'F') {
                if(K[b].winny) {
                   if(kogo[a] == K[b].kogo)
                      klamca[a] = true;
                   else
                      kogonie[a].insert(K[b].kogo);
                }
                else {
                   if(kogo[a] && kogo[a] != K[b].kogo)
                      klamca[a] = true;
                   else
                      kogo[a] = K[b].kogo;
                }
                K[i] = zez(a, K[b].kogo, !K[b].winny);
             }
          }
          licz();
       }
       return 0;
}
       
