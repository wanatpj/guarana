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

inline long long nwd2(long long a, long long b)
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
        r=nwd(p,q);
        p/=r;
        q/=r;
        if(p>q)
        {
            odp=(long long)p*q;
            tmp=(long long)q*(q-1)/2;
            odp-=tmp;
        }
        else
        {
            tmp=(long long)p*q;
            odp=(long long)p*(p+1)/2;
            tmp-=odp;
        }
        nw=nwd2(odp,tmp);
        printf("%lld %lld\n",odp/nw,tmp/nw);
    }
    return 0;
}
