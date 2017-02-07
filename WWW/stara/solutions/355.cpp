#include<algorithm>
#include<cstdio>
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

int OUT[MAX+1];
bool klamca[MAX+1];
int naniego[MAX+1];

int n,m;

int a,b;
char c;

int ile;

void licz() {
     int mi = 1000000000;
     FOR(i,1,n)
        mi = min(mi, ile - naniego[i]);
     FOR(i,1,n)
        if(ile - naniego[i] == mi)
           printf("%d ",i);
     printf("\n");
}

void vanish() {
     FOR(i,1,n)
        naniego[i] = OUT[i] = klamca[i] = 0;
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
             if(c == 'W')
                K[i] = zez(a, b, true);
             else if(c == 'P') {
                K[i] = zez(a, K[b].kogo, K[b].winny);
             }
             else if(c == 'F') {
                K[i] = zez(a, K[b].kogo, !K[b].winny);
             }
             ile += K[i].winny;
             OUT[a] += K[i].winny;
             klamca[a] = (OUT[a] > 1);
             naniego[K[i].kogo] += K[i].winny;
             
             //printf("%d %d %d\n",K[i].kto, K[i].kogo, K[i].winny);
          }
          licz();
       }
       return 0;
}
       
