#include<algorithm>
#include<cstdio>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)

int n,m;
int a,b,c;

main() {
       scanf("%d %d",&n,&m);
       while(n--)
       {
          scanf("%d %d %d",&a,&b,&c);
          if(a > m)
             printf("komin\n");
          else if(b > m)
             printf("okno\n");
          else if(c > m)
             printf("drzwi\n");
          else
             printf("brak\n");
       }
       return 0;
}
       
