#include<cstdio>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

const int MAX = 200;
const int INF = 1000000001;

struct jak {
   int koszt;
   int naw;
   jak() {
      koszt = naw = 0;
   }
   jak(int koszt1, int naw1) {
      koszt = koszt1;
      naw = naw1;
   }
};

//inline jak min(const jak &A, const jak &B) {
//    return A < B ? A : B;
//}

jak tab[MAX+1][MAX+1];
int DL[MAX+1];

int n;
int x;

inline void licz() {
     int temp;
     int tempnaw;
     FOR(d,2,n)
     {
        FOR(i,1,n-d+1)
        {
           tab[d][i] = jak(INF, 0);
           FOR(k,i,i+d-2)
           {
              temp = DL[k] - DL[i-1] + DL[i+d-1] - DL[k] + tab[k-i+1][i].koszt + tab[i+d-2-k+1][k+1].koszt;
              tempnaw = tab[k-i+1][i].naw + tab[i+d-2-k+1][k+1].naw + (k != i+d-2);
              if(temp < tab[d][i].koszt)
                 tab[d][i] = jak(temp, tempnaw);
              else if(temp == tab[d][i].koszt && tempnaw < tab[d][i].naw)
                 tab[d][i].naw = tempnaw;
              //tab[d][i] = min(tab[d][i], jak(DL[k] - DL[i-1] + DL[i+d-1] - DL[k] + tab[k-i+1][i].koszt + tab[i+d-2-k+1][k+1].koszt, tab[k-i+1][i].naw + tab[i+d-2-k+1][k+1].naw + (k != i+d-2)));
           }
           //printf("tab[%d][%d] %d\n",d,i,tab[d][i].koszt);
        }
     }
     printf("%d %d\n",tab[n][1].koszt, tab[n][1].naw);
}

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d",&n);
          FOR(i,1,n)
          {
             scanf("%d",&x);
             tab[1][i] = jak(0, 0);
             DL[i] = DL[i-1] + x;
          }
          licz();
       }
       return 0;
}
