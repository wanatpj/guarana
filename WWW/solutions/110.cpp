#include<cstdio>
#include<algorithm>
using namespace std;

#define FOR(x,y,z) for(long long x=y;x<=z;++x)
#define REP(x,y) for(long long x=0;x<y;++x)

#define DBGa
#define LL long long

LL n,k,m;

LL max(LL a, LL b) {
   return a > b ? a : b;
}
LL min(LL a, LL b) {
   return a < b ? a : b;
}

LL pot(LL a) {
   LL wyn = 1;
   LL temp = a;
   int ex = m - 2;
   while(ex)
   {
      if(ex&1)
         wyn = (wyn*temp)%m;
      temp = (temp*temp)%m;
      ex /= 2;
   }
   return wyn;
}

LL liczn(LL a) {
    LL wyn = 1;
    FOR(i,a+1,n)
       wyn = (wyn*i) % m;
    return wyn;
}

LL mian(LL a) {
    LL wyn = 1;
    FOR(i,1,a)
       wyn = (wyn*i) % m;
    return wyn;
}

void licz() {
     LL a;
     LL j;
     LL wieksze,mniejsze;
     LL licznik,mianownik;
     REP(i,k)
     {
        a = 0;
        j = 0;
        #ifdef DBG
        printf("i-> %d\n",i);
        #endif
        while(j*k + i <= n)
        {
           #ifdef DBG
           printf("j-> %lld %lld %lld\n",j,j*k+i,n-j*k-i);
           #endif
           wieksze = max(j*k+i,n-j*k-i);
           mniejsze = min(j*k+i,n-j*k-i);
           #ifdef DBG
           printf("mn-> %d wi-> %d\n",mniejsze,wieksze);
           #endif
           licznik = liczn(wieksze);
           mianownik = mian(mniejsze);
           #ifdef DBG
           printf("licz-> %d mian-> %d\n",licznik,mianownik);
           #endif
           if(mianownik == 0) { ++j; continue; }
           //while(licznik % mianownik != 0)
           //   licznik += m;
           
           a = (a + (licznik * pot(mianownik))) % m;
           ++j;
        }
        printf("%lld\n",a%m);
     }
}

main() {
       scanf("%lld %lld %lld",&n,&k,&m);
       licz();
       return 0;
}
       
