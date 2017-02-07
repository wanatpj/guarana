#include <iostream>
#define MAX 1010

int n,k,m,l;
int w[MAX], tro[100000];

void pas()
{
    for(int i=1;i<=n;i++) tro[i]=0;
    tro[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>0;j--)
        {
            tro[j]=tro[j]+tro[j-1];
            if(tro[j]>=m) tro[j]-=m;
        }
    }
    l=0;
    for(int i=0;i<=n;i++)
    {
        w[l]+=tro[i];
        if(w[l]>=m) w[l]-=m;
        l++;
        if(l==k) l=0;
    }
}

main()
{
    scanf("%d %d %d",&n,&k,&m);
    for(int i=0;i<k;i++) w[i]=0;
    if(m!=1) pas();
    for(int i=0;i<k;i++) printf("%d\n",w[i]);
    return 0;
}
