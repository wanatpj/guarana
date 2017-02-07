//brute
#include<cstdio>
#include<cmath>
int main()
{
    int n,z;
    scanf("%d", &z);
    while(z--){
    scanf("%d", &n);
    long double sum=0;
    for(int i=1;i<=n;i++)
        sum+=1/(long double)i;
        printf("%lf\n", (double)sum);
    }
    return 0;
}
