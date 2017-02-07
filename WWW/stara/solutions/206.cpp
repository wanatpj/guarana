#include<cstdio>
long long J(long long n){
    if(n==1) return 1;
    if(n&1) return (2*J(n/2+1)+n-2)%(n+1);
    return 2*J(n/2)-1;
}
int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld", J(n));
    return 0;
}
