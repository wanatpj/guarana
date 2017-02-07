#include<cstdio>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

const int MAXS = 31630;

bool P[MAXS];

int dz[3500];
int iledz = 0;

int n, m;

void sito() {
     P[2] = true;
     dz[iledz++] = 2;
     for(int i=4;i<MAXS;i+=2)
     {
        P[i] = false;
        P[i-1] = true;
     }
     for(int i=3;i<MAXS;i+=2)
     {
        if(!P[i])
           continue;
        dz[iledz++] = i;
        for(int j=(i<<1);j<MAXS;j+=i)
           P[j] = false;
     }
}

void licz() {
     long long suma = 1;
     int i = 0;
     long long alfak;
     for(;dz[i]*dz[i]<=n;++i)
     {
        alfak = dz[i];
        while(n % dz[i] == 0)
        {
           alfak *= dz[i];
           n /= dz[i];
        }
        if(alfak == dz[i])
           continue;
        //printf("%d %d\n",dz[i],alfak);
        suma = (suma * ((alfak-1)/(dz[i]-1))) % m;
     }
     if(n != 1)
        suma = (suma + n) % m;
     printf("%lld\n",suma);
}

main() {
       sito();
       int z;
       scanf("%d %d", &z, &m);
       while(z--)
       {
          scanf("%d", &n);
          licz();
       }
       return 0;
}
       
