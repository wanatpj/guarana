#include<cstdio>
int n,m,k;
int t[1000];
void sudo_calc(){
    t[0]=1;
    for(int i=1;i<k;++i)
        t[i]=0;
    int x;
    for(int i=1;i<=n;++i){
        x=t[0]+t[k-1];
        if(x>m)x-=m;
        for(int j=k-1;j>0;--j){
            t[j]+=t[j-1];
            if(t[j]>m) t[j]-=m;
        }
        t[0]=x;
    }
}
int main()
{
    scanf("%d%d%d", &n, &k, &m);
    sudo_calc();
    for(int i=0;i<k;i++)
        printf("%d\n", t[i]);
    return 0;
}
