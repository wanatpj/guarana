#include<cstdio>
int n,k,m;
int res[1000000];
int nk[10000][10000];
void pre(){
    for(int i=0;i<10000;i++){
        nk[0][i]=0;
        nk[i][0]=1;
    }
    for(int i=1;i<10000;i++)
    for(int j=1;j<10000;j++){
        nk[i][j]=nk[i-1][j-1]+nk[i-1][j];
        if(nk[i][j]>m) nk[i][j]-=m;
    }
    for(int i=0;i<100000;i++)
        res[i]=0;
}
int main()
{
    scanf("%d%d%d", &n, &k, &m);
    pre();
    if(m==1){
        for(int i=0;i<k;i++)
            printf("0\n");
        return 0;
    }
    for(int i=0;i<=n;i++){
        res[i%k]+=nk[n][i];
        res[i%k]%=m;
    }
    for(int i=0;i<k;i++)
        printf("%d\n", res[i]);
    return 0;
}
