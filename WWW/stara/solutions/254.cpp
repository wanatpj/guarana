#include<cstdio>
using namespace std;
int n,m,kom,ok,drz;
int main()
{
    scanf("%d%d",&n,&m);
    while(n--)
    {	scanf("%d%d%d",&kom,&ok,&drz);
	if(m<kom)
	    printf("komin\n");
	else if(m<ok)
	    printf("okno\n");
	else if(m<drz)
	    printf("drzwi\n");
	else
	    printf("brak\n");
    }
return 0;
}