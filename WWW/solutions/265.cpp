#include<cstdio>
int main()
{
    int D,N;
    scanf("%d", &D);
    int sum,x;
    while(D--){
        sum=0;
        scanf("%d", &N);
        while(N--){
            scanf("%d", &x);
            sum+=x;
        }
        scanf("%d", &x);
        if(sum==0) printf("%d\n", x);
        else printf("%d\n", x%sum);
    }
    return 0;
}
