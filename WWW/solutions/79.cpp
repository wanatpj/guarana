#include <iostream>
#define MAX 1010

int n,k,m,l;
int w[MAX];
long long last, r;

int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<k;i++) w[i]=0;
    l=1; r=n+1;
    last=1; w[0]=1;
    for(int i=1;i<=n;i++)
    {
        last=last*(r-i)/i;
        last%m;
        w[l]+=last;
        w[l]%m;
        l++;
        if(l>=k) l-=k;
    }
    for(int i=0;i<k;i++) printf("%d\n",w[i]);
    return 0;
}
