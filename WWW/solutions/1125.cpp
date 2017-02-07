#include<cstdio>
#include<cmath>
long long wynik(long long n){
    if(n==1) return 1;
    long long tmp = (long long)pow(2, floor(log2(n)));
    if(n==tmp)
        return 1&(long long)floor(log2(n));
    return 1^wynik(n-tmp);
}
int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld", wynik(n));
    return 0;
}
