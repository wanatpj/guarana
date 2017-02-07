//slabe ograniczenie
#include<cstdio>
#include<cmath>
#define C 1000000LL
double t[C];
int main()
{
    t[0]=1;
    for(double i=1;i<C;i++)
        t[(int)i]=t[(int)i-1]+1/(i+1);
    long long n;
    int z;
    scanf("%d", &z);
    while(z--){
        scanf("%lld", &n);
        if(n<=C)
            printf("%lf\n", t[n-1]);
        else printf("%lf\n", t[C-1]+log(n)-log(C));
    }
    return 0;
}
