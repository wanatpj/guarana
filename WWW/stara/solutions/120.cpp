#include <iostream>

int n,m,a,b,c,f1,f2,res;

int main()
{
    res=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&f1,&f2);
        if(f2==1&&f1==0) res++;
    }
    printf("%d\n",res);
    return 0;
}
