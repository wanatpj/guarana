#include<cstdio>
#include<algorithm>
using namespace std;

#define FOR(x,y,z) for(long long x=y;x<=z;++x)
#define REP(x,y) for(long long x=0;x<y;++x)

const int MAX = 1000000;

#define DBGa
#define LL int

int newton[MAX];

LL n,k,m;

LL max(LL a, LL b) {
   return a > b ? a : b;
}
LL min(LL a, LL b) {
   return a < b ? a : b;
}

void licz() {
     newton[0] = newton[1] = 1;
     FOR(i,2,n)
     {
        newton[i] = 1;
        for(int j=i-1;j>=(i)/2;--j)
            {newton[j] = (newton[j] + newton[j-1]) % m; newton[i-j-1] = newton[j+1];}
     }
}

main() {
       scanf("%d %d %d",&n,&k,&m);
       licz();
       int a;
       FOR(i,0,k-1)
       {
          a = 0;
          for(int j=0;j*k+i<=n;++j)
             a = (a + newton[j*k+i]) % m;
          printf("%d\n",a);
       }
       return 0;
}
       
