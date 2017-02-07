#include<cstdio>

#define LL long long
#define FOR(x,y,z) for(int x=y;x<=z;++x)

#define DBGa

const int MAXL = 32;

LL p,a,b,c,d,x,n;

LL A[MAXL],B[MAXL],C[MAXL],D[MAXL];

int wyk;

LL pot(int q) {
   LL wyn = 1;
   LL temp = q;
   wyk = p-2;
   while(wyk)
   {
      if(wyk & 1)
         wyn = (wyn * temp) % p;
      temp = (temp * temp) % p;
      wyk >>= 1;
   }
   return wyn;
}

void uzup() {
   FOR(i,1,MAXL-1)
   {
      A[i] = ( (A[i-1]*A[i-1])%p + (B[i-1]*C[i-1])%p ) % p;
      B[i] = ( (A[i-1]*B[i-1])%p + (B[i-1]*D[i-1])%p ) % p;
      C[i] = ( (C[i-1]*A[i-1])%p + (C[i-1]*D[i-1])%p ) % p;
      D[i] = ( (B[i-1]*C[i-1])%p + (D[i-1]*D[i-1])%p ) % p;
   }
}

LL F(LL X, int lvl) {
   LL mian,licz;
   
   licz = (A[lvl]*X + B[lvl]) % p;
   mian = (C[lvl]*X + D[lvl]) % p;
   
   mian = pot(mian);
   
   return (licz * mian) % p;
}

LL licz() {
   int potega = 1;
   int wykladnik = 0;
   while(potega < n)
   {
      potega <<= 1;
      ++wykladnik;
   }
   while(potega)
   {
      if(n > potega) {
         n -= potega;
         x = F(x,wykladnik);
      }
      --wykladnik;
      potega >>= 1;
   }
   return x;
}

main() {
       int k;
       scanf("%d",&k);
       while(k--)
       {
          scanf("%lld %lld %lld %lld %lld %lld %lld",&p,&A[0],&B[0],&C[0],&D[0],&x,&n);
          ++n;
          uzup();
          printf("%lld\n",licz());
       }
       return 0;
}
       
