#include<cstdio>
int main()
{
    unsigned long long t[3];
    scanf("%llu", &t[0]);
    for(int i=1;i<=2;i++)
        t[i]=t[0]+i;
    for(int i=0;i<3;i++)
        if(t[i]%2==0)
            {t[i]/=2; break;}
    for(int i=0;i<3;i++)
        if(t[i]%3==0)
            {t[i]/=3; break;}
    printf("%llu", t[0]*t[1]*t[2]);
    return 0;
}
