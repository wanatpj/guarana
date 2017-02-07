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
bool pusty[MAX+1];
bool tylkonie[MAX+1];
int iletylko[MAX+1];

int n,m;

int a,b;
char c;

int ile;

void licz() {
     int ile = 0;
     int pustych = 0;
     int iletylkonie = 0;
     FOR(i,1,n)
     {
        if(kogonie[i].size() == n)
           klamca[i] = true;
        if(klamca[i])
           kogo[i] = 0;
        if(!klamca[i] && kogo[i])
           ++ile;
        if(!klamca[i] && kogo[i] == 0 && kogonie[i].size() == 0) {
           pusty[i] = true;
           ++pustych;
        }
        if(!klamca[i] && kogo[i] == 0 && kogonie[i].size() != 0) {
           ++iletylkonie;
           tylkonie[i] = true;
           for(set<int>::iterator it=kogonie[i].begin();it!=kogonie[i].end();++it)
              ++iletylko[(*it)];
        }
        if(!klamca[i] && kogo[i])
           ++naniego[kogo[i]];
     }
     
     //FOR(i,1,n) printf("%d naniego %d naniegonie %d klamca %d kogo %d tylkonie %d\n",i,naniego[i],naniegonie[i],klamca[i],kogo[i],tylkonie[i]);printf("pustych %d\n",pustych);
     int mi = 1000000000;
     
     //int bec = n - pustych - 
     
     FOR(i,1,n)
     {
        //printf("%d %d\n",i,n - pustych - naniego[i] - 0*(kogo[i]==i) - iletylkonie + iletylko[i]);
        mi = min(mi, n - pustych - naniego[i] - 0*(kogo[i]==i) - iletylkonie + iletylko[i]);
     }
     FOR(i,1,n)
        if(n - pustych - naniego[i] - 0*(kogo[i]==i) - iletylkonie + iletylko[i] == mi)
           printf("%d ",i);
     printf("\n");
}

void vanish() {
     FOR(i,1,n)
     {
        naniego[i] = naniegonie[i] = kogo[i] = klamca[i] = pusty[i] = iletylko[i] = tylkonie[i] = 0;
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
                if((kogo[a] && kogo[a] != b) || kogonie[a].find(b) != kogonie[a].end()) {
                   klamca[a] = true;
                }
                else {
                   kogo[a] = b;
                }
                K[i] = zez(a, b, true);
             }
             else if(c == 'P') {
                if(K[b].winny) {
                   if((kogo[a] && kogo[a] != K[b].kogo) || kogonie[a].find(K[b].kogo) != kogonie[a].end())
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
       
