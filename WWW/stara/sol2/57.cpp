#include<cstdio>
int main()
{
    unsigned long long a=0,n,i=1;
    scanf("%llu", &n);
    for(;i<=n;i++) a+=i*(i+1)/2;
    printf("%llu\n", a);
    return 0;
}