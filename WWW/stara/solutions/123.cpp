#include<cstdio>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)

#define DBG
int n,m;

int a,b,w,f1,f2;

int wynik;

main() {
       scanf("%d %d",&n,&m);
       FOR(i,1,m)
       {
          scanf("%d %d %d %d %d",&a,&b,&w,&f1,&f2);
          if(f1 && !f2)
             ++wynik;
       }
       printf("%d",wynik);
       return 0;
}
       
