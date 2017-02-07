#include <iostream>

int z,n,c,s,tmp;

int main()
{
    scanf("%d",&z);
    while(z--)
    {
        s=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            s+=tmp;
        }
        scanf("%d",&c);
        if(s==0) printf("%d\n",c);
        else printf("%d\n",c%s);
    }
    return 0;
}