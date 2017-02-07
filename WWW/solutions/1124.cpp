#include<cstdio>
int main()
{
    long long n,cnt=0;
    scanf("%lld", &n);
    while(n){
        if(n&1) cnt++;
        n/=2;
    }
    printf("%lld\n", cnt&1);
    return 0;
}
