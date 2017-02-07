#include <iostream>
using namespace std;

int main()
{
    int n,m,a,b,c,f1,f2,ilea,ileb;
    ilea=ileb=0;
    scanf("%d%d", &n, &m);
    while(m--)
    {
	scanf("%d%d%d%d%d", &a,&b,&c,&f1,&f2);
	if(f1==1 && f2==0) ++ilea;
	if(f1==0 && f2==1) ++ileb;
    }
    if(ilea==ileb) printf("%d\n", ilea);
    else printf("NIE\n");
return 0;
}