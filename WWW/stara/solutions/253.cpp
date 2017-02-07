#include<cstdio>
using namespace std;
int d,c,n,x,il=0;
int main()
{
    scanf("%d",&d);
    while(d--)
    {	il=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
	    scanf("%d",&x);
	    il += x;
	}
	scanf("%d",&c);
	if( il!=0 )
	    printf("%d\n",c%il);
	else
	    printf("%d\n",c);    
    }
return 0;
}