#include<cstdio>
#define MOD 1000000000
#define MAX 331
struct BI{
    long long c[60];
    int size;
    BI(){}
    BI(long long x){
        size=0;
        while(x>0){
            c[size]=x%MOD;
            ++size;
            x/=MOD;
        }
        if(size==0) {size=1; c[0]=0;}
        c[size]=0;
    }
};
BI operator*(BI A, long long x){
    for(int i=0;i<A.size;i++)
        A.c[i]*=x;
    for(int i=0;i<A.size;i++){
        A.c[i+1]+=A.c[i]/MOD;
        A.c[i]%=MOD;
    }
    while(A.c[A.size]!=0){
        A.c[A.size+1]=A.c[A.size]/MOD;
        A.c[A.size]%=MOD;
        ++A.size;
    }
    return A;
}
BI operator+(BI A, BI B){
    if(A.size<B.size){
        for(int i=A.size;i<=B.size;i++)
            A.c[i]=0;
        A.size=B.size;
    }
    else
        for(int i=B.size;i<=A.size;i++)
            B.c[i]=0;
    for(int i=0;i<A.size;i++){
        A.c[i]+=B.c[i];
        A.c[i+1]+=A.c[i]/MOD;
        A.c[i]%=MOD;
    }
    while(A.c[A.size]!=0){
        A.c[A.size+1]=A.c[A.size]/MOD;
        A.c[A.size]%=MOD;
        ++A.size;
    }
    return A;
}
BI tab[MAX][MAX];
void printtf(int n,int k){
    BI x = tab[n][k];
    printf("%lld", x.c[x.size-1]);
    for(int i=0;i<x.size-1;i++)
        printf("%09lld", x.c[x.size-2-i]);
}
void prepare()
{
    for(int i=1;i<MAX;i++)
        tab[0][i]=BI(0);
    for(int i=0;i<MAX;i++)
        tab[i][0]=BI(1);
    for(int i=1;i<MAX;i++)
    for(int j=1;j<MAX;j++)
        tab[i][j]=tab[i-1][j-1]+tab[i-1][j]*(long long)(j+1);
}
int main()
{
    prepare();
    int t,n,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        printtf(n-1,k-1);
        printf("\n");
    }
    return 0;
}
