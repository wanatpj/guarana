#include<algorithm>
#include<cstdio>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

int n, ile, c;
int x;

main() {
       int z;
       scanf("%d",&z);
       while(z--)
       {
          scanf("%d",&n);
          ile = 0;
          while(n--)
          {
             scanf("%d",&x);
             ile += x;
          }
          scanf("%d",&c);
          printf("%d\n",ile ? c % ile : c);
       }
       return 0;
}
       
