#include <iostream>
#define MAXB 1000

int k,a,b,si,maxi,w,z,n;
bool ok;
bool tab[MAXB][MAXB];
bool tmp[MAXB];

int main()
{
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) tab[i][j]=0;
        for(int i=2;i<=n;i++)
        {
            a=i;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                scanf("%d",&b);
                tab[a][b]=1;
                tab[b][a]=1;
            }
        }
        k=(1<<n);
        maxi=1;
        w=1;
        for(int i=2;i<k;i++)
        {
            a=i;
            b=1;
            si=0;
            for(int j=1;j<=n;j++) tmp[j]=0;
            while(a>0)
            {
                if(a%2==1)
                {
                    tmp[b]=1;
                    si++;
                }
                b++;
                a/=2;
            }
            if(si>maxi)
            {
                ok=1;
                for(int x=1;x<=n;x++)
                {
                    if(!tmp[x]) continue;
                    for(int y=x+1;y<=n;y++)
                    {
                        if(!tmp[y]) continue;
                        if(!tab[x][y])
                        {
                            ok=0;
                            break;
                        }
                    }
                }
                if(ok)
                {
                    maxi=si;
                    w=i;
                }
            }
        }
        for(int j=1;j<=n;j++) tmp[j]=0;
        a=w;
        b=1;
        while(a>0)
        {
            if(a%2==1)
            {
                tmp[b]=1;
            }
            b++;
            a/=2;
        }
        printf("%d\n",maxi);
        for(int i=1;i<=n;i++) if(tmp[i]) printf("%d ",i);
        printf("\n");
    }
    return 0;
}
