#include<cstdio>
using namespace std;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define REP(x,y) for(int x=0;x<y;++x)

#define DBGa
#define LL int

LL p,q;

LL NWD(LL a, LL b) {
    return b ? NWD(b,a%b) : a;
}

LL suma(LL n) {
    return ((n+1)*n)/2;
}

LL gcd;

LL P,Q;

void Pw() {
     #ifdef DBG
     printf("Pw\n");
     #endif
     LL roznica1,roznica2;
     LL roz;
     roz = q % p;
     int a = 2;
     while(roz <= p && roz >= q-p)
        roz = (q*a++) % p;
     
     if(roz <= p)
        Q = suma(p);
     else
        Q = suma(q-1) - suma(q-p-1);
     
     P = p*q - Q;
     return;
     
     roznica2 = (2*q) % p;
     
     if(roznica1 > roznica2) {
        #ifdef DBG
        printf("roz1\n");
        #endif
        Q = suma(q-1) - suma(q-p-1);
     }
     else {
        #ifdef DBG
        printf("roz2\n");
        #endif
        Q = suma(p);
     }
     
     P = p*q - Q;
}

void Qw() {
     #ifdef DBG
     printf("Qw\n");
     #endif
     LL roznica1,roznica2;
     
     LL roz;
     /*roz = q % p;
     int a = 2;
     int b = 1;
     LL tempq = q;
     while(tempq < p) tempq += q;
     while(roz <= q && roz >= p-q)
        roz = (p*a++) % q;
     
     if(roz <= p)
        P = suma(p);
     else*/
        P = suma(p) - suma(p-q);
     
     Q = p*q - P;
     return;
     
     roznica1 = (2*p) % q;
     roznica2 = (3*p) % q;
     //if(roznica2 == 0)
     //   roznica2 = q;
     if(roznica1 < roznica2) {
        #ifdef DBG
        printf("roz1\n");
        #endif
        P = suma(p) - suma(p-q);
        #ifdef DBG
        printf("P: %d",P);
        #endif
     }
     else {
        #ifdef DBG
        printf("roz2\n");
        #endif
        P = suma(q);
     }
     
     Q = p*q - P;
     #ifdef DBG
     printf("Q: %d\n",Q);
     #endif
}

main() {
       int t;
       scanf("%d",&t);
       while(t--)
       {
          scanf("%lld %lld",&p,&q);
          gcd = NWD(p,q);
          p /= gcd;
          q /= gcd;
          if(q == 1) {
             printf("%lld 0\n",p);
             continue;
          }
          if(p == 1) {
             printf("1 %lld\n",q-1);
             continue;
          }
          if(p < q) {
             Pw();
          }
          else {
             Qw();
          }
          gcd = NWD(P,Q);
          #ifdef DBG
          printf("%lld %lld nwd: %lld\n",P,Q,gcd);
          #endif
          printf("%lld %lld\n",P/gcd,Q/gcd);
       }
       return 0;
}
       
