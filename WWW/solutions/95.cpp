#include <iostream>

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

int n;
long long odp,tmp,nw,p,q,r;

main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld %lld",&p,&q);
        r=nwd(p,q);
        p/=r;
        q/=r;
        if(p>q)
        {
            odp=p*q;
            tmp=(q*(q-1))/2;
            odp-=tmp;
        }
        else
        {
            tmp=p*q;
            odp=(p*(p+1))/2;
            tmp-=odp;
        }
        nw=nwd(odp,tmp);
        printf("%lld %lld\n",odp/nw,tmp/nw);
    }
    return 0;
}
