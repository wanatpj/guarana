#include<cstdio>
int main()
{
    int n,k,m,b,c;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &k, &m);
        m-=5*k;
        c=m%100;
        m/=100;
        m-=5*k;
        b=m%100;
        m/=100;
        printf("%02d-%02d-%02d\n", m, b, c);
    }
    return 0;
}
