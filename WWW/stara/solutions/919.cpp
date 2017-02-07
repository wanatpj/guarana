#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

typedef long long LL;

const int MAX = 10000;

int tab[MAX];

int n;

void licz() {
     switch(n)
     {
        case 1:
           printf("%d\n",tab[0]);
        break;
        case 2:
           printf("%d\n",tab[1]);
        break;
        default:
           LL wynik = 0;
           int i;
           for(i=n-1;i>2;i-=2)
              wynik += min(tab[i] + tab[0] + (tab[1]<<1), tab[i] + tab[i-1] + (tab[0]<<1));
           if(i == 2)
              wynik += tab[0] + tab[1] + tab[2];
           else
              wynik += tab[1];
           printf("%lld\n",wynik);
        break;
     }
}

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d",&n);
          REP(i,n)
             scanf("%d",&tab[i]);
          sort(tab, tab+n);
          licz();
       }
       return 0;
}
       
