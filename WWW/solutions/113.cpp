#include <iostream>
#define MAX 1010

int n,k,m,l,tmp;
int w[MAX];

void pas()
{
    w[0]=1;
    for(int i=1;i<=n;i++)
    {
        tmp=w[k-1];
        for(int j=k-1;j>0;j--)
        {
            w[j]+=w[j-1];
            if(w[j]>=m) w[j]-=m;
        }
        w[0]+=tmp;
        if(w[0]>=m) w[0]-=m;
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

