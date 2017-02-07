#include<cstdio>
int n,k,m;
int nk[1000000];
void pre(){
    nk[0]=1;
    for(int i=1;i<=n;i++){
        nk[i]=0;
    }
    for(int i=1;i<=n;++i)
    for(int j=n;j>0;--j){
        nk[j]+=nk[j-1];
        if(nk[j]>m) nk[j]-=m;
    }
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
    long long tmp;
    for(int i=0;i<k;i++){tmp=0;
    for(int j=0;j*k+i<=n;j++)
        tmp+=nk[j*k+i];
        printf("%d\n", (int)(tmp%(long long)m));
    }
    return 0;
}
