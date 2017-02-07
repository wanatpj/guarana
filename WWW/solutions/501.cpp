#include<cstdio>
#include<algorithm>
long long C,M;
long long randomowa;
bool sito[100000];
//long long dzieln[100000];
int nb;
long long primes[1000];
long long mpri;
long long power(long long a, long long b, long long &c){
    long long res=1;
    while(b>0){
        if(b&1LL){
            res*=a;
            res%=c;
        }
        a*=a;
        a%=c;
        b/=2;
    }
    return res;
}
bool isPrime(long long n){
    long long x=n-1,y;
    while(x&1LL==0)
        x/=2;
    long long r;
    for(int i=0;i<10;++i){y=x;
        r=2+rand()%(n-2);
        r=power(r,x,n);
        if(r==1||r==n-1) continue;
        while(y!=n-1){
            r*=r;
            r%=n;
            y<<=1;
            if(r==1) return false;
            else if(r==n-1) break;
        }
        if(y==n-1&&r!=1) return false;
    }
    return true;
}
long long gcd(long long a, long long b){
    long long c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
void pre(){
    for(int i=3;i<100000;i++)
        sito[i]=1;
    primes[0]=2;
    nb=1;
    int tmp;
    for(int i=3;nb<1000;i+=2)
        if(sito[i]){
            tmp=3*i;
            while(tmp<100000){
                sito[tmp]=0;
                tmp+=2*i;
            }
            primes[nb]=i;
            ++nb;
        }
    mpri=primes[999];
}
inline long long f(long long n){
    return n*n+3;
}
inline long long g(long long n){
    return n*n+1;
}
inline long long h(long long n){
    return n*n+randomowa;
}
long long d2(long long n){
    if(isPrime(n)) return n+1;
    int x=2,y=2,d=1;
    while(d==1){
        x=f(x)%n;
        y=f(f(y)%n)%n;
        d=gcd(abs(x-y),n);
    }
    if(d!=n) return (1+d)*(1+n/d);
    x=2;y=2;d=1;
    while(d==1){
        x=g(x)%n;
        y=g(g(y)%n)%n;
        d=gcd(abs(x-y),n);
    }
    if(d!=n) return (1+d)*(1+n/d);
    x=2;y=2;d=1;
    while(d==1){
        x=h(x)%n;
        y=h(h(y)%n)%n;
        d=gcd(abs(x-y),n);
    }
    if(d!=n) return (1+d)*(1+n/d);
    return n+1;
}
long long d(long long n){
//    if(n<100000)
//      return d3(n);
    long long suma=1,msuma;
    for(int i=0;i*i<=n;++i)
        if(n%primes[i]==0){
            msuma=1;
            while(n%primes[i]==0){
                msuma*=primes[i];
                ++msuma;
                msuma%=M;
                n/=primes[i];
            }
            suma*=msuma;
            suma%=M;
        }
    if(n>1) {suma*=d2(n); suma%=M;}
    return suma;
}
int main()
{
    pre();
    long long n;
    srand(time(NULL));
    scanf("%lld%lld", &C, &M);
    randomowa = rand()%M;
    while(C--){
        scanf("%lld", &n);
        printf("%lld\n", d(n));
    }
    return 0;
}
