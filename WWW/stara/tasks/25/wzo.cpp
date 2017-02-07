#include <iostream>
using namespace std;

long long k,p,a,b,c,d,n,x,g,m;
struct homo { long long a,b,c,d; } f1,f2;

homo operator*(const homo &a, const homo &b)
{
     homo tmp;
     tmp.a=(a.a*b.a+a.b*b.c)%p; 
     tmp.b=(a.b*b.d+b.b*a.a)%p;
     tmp.c=(a.c*b.a+a.d*b.c)%p;
     tmp.d=(a.d*b.d+b.b*a.c)%p;
     return tmp;     
}

void pot()
{
     bool ok=0;
     f2.a=a;
     f2.b=b;
     f2.c=c;
     f2.d=d;
     while(n>0)
     {
          if((n&1)==1) 
          {
              if(ok==0)
              {
                   f1=f2;
                   ok=1;         
              }
              else
              {
                  f1=f1*f2;
              }
          }     
          f2=f2*f2;     
          n/=2;     
     }     
}

long long euclid(long long a, long long b, long long &l, long long &k)
{
     if(a==0)
     {
          l=0;
          k=1;
          return b;    
     }     
     long long d=euclid(b%a,a,k,l);
     l-=(b/a)*k;
     l%=p;
     if(l<0) l+=p;
     return d;
}

int main()
{
      scanf("%lld",&k);      
      while(k--)
      {
           scanf("%lld %lld %lld %lld %lld %lld %lld",&p, &a, &b, &c, &d, &x, &n);          
           pot(); 
           g=(f1.a*x+f1.b)%p;
           m=(f1.c*x+f1.d)%p;
           //M*m=1(modp)
           long long y, M;
           euclid(m,p,M,y);
           printf("%lld\n",(g*M)%p); 
      }
      return 0;      
}

