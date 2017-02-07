#include <iostream>

long long n;

long long fla(long long a)
{
    if(a==1) return 1;
    if(a&1) return (fla(a/2)<<1)+1;
    return (fla(a/2)<<1)-1;
}

main()
{
    scanf("%lld",&n);
    printf("%lld",fla(n));
    return 0;
}
