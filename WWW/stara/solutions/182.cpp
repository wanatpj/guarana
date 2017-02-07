#include<cstdio>
long long p;
struct funct{
    long long a,b,c,d;
    funct(){}
    funct(long long a, long long b, long long c, long long d){
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
    }
    funct operator*(funct &A){
        funct res;
        res.a=(a*A.a+A.c*b)%p;
        res.b=(a*A.b+A.d*b)%p;
        res.c=(c*A.a+A.c*d)%p;
        res.d=(c*A.b+A.d*d)%p;
        return res;
    }
};
funct potega(funct f, long long n){//
    funct res = funct(1,0,0,1);
    while(n){
        if(n&1LL)
            res=res*f;
        f=f*f;
        n/=2;
    }
    return res;
}
long long power(long long a, long long b){
    long long res=1;
    while(b>0){
        if(b&1LL){
            res*=a;
            res%=p;
        }
        a*=a;
        a%=p;
        b/=2;
    }
    return res;
}
int main()
{
    int k;
    scanf("%d", &k);
    funct R;
    long long x,n,l,m;
    while(k--){
        scanf("%lld%lld%lld%lld%lld%lld%lld", &p, &R.a, &R.b, &R.c, &R.d, &x, &n);
        R = potega(R,n);
        if(R.a<0) R.a+=p;
        if(R.b<0) R.b+=p;
        if(R.c<0) R.c+=p;
        if(R.d<0) R.d+=p;
        x%=p;
        l=R.a*x+R.b;
        m=R.c*x+R.d;
        l%=p;
        m%=p;
        printf("%lld\n", (l*power(m,p-2))%p);
    }
    return 0;
}
