#include <iostream>

inline int nwd(int a, int b)
{
    int tmp;
    while(a>0)
    {
        tmp=a;
        a=b%a;
        b=tmp;
    }
    return b;
}

inline long long nwd(long long a, long long b)
{
    long long tmp;
    while(a>0)
    {
        tmp=a;
        a=b%a;
        b=tmp;
    }
    return b;
}

int n,p,q,r;
long long odp,tmp,nw;

main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&p,&q);
        //printf("%d\n",nwd(p,q));
        r=nwd(p,q);
        p/=r;
        q/=r;
        odp=p*q;
        tmp=q*(q-1)/2;
        odp-=tmp;
        nw=nwd(odp,tmp);
        printf("%lld %lld\n",odp/nw,tmp/nw);
    }
    return 0;
}