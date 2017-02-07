#include<cstdio>
using namespace std;
int pier[10000],c,m,n,il_pier=0;
bool uzyt[100007];
void sito()
{	for(int i=2;i<=100000;++i)
	{	if(!uzyt[i])
		{	for(int j=i;j<=100000;j+=i)
				uzyt[j]=true;
			pier[++il_pier] = i;
		}
	}
}
long long dzielniki(int *tab)
{	long long wyn=1;
	while((*tab)*(*tab) <= n)
	{
		//printf("lic_p=%d n=%d\n",*tab,n);
		if( !( n%(*tab) ) )
		{	long long mnoz=0;
			while( !(n%(*tab) ) )
			{	mnoz *= (*tab);
				mnoz += *tab;
				n/= *tab;
			}
			wyn *= (mnoz+1);
		}
		++tab;
	}
	//printf("wyn=%d\n",wyn);
	if( wyn == 1)
		return n+1;
	else if( n>1 )
		wyn *= (n+1);
return wyn;
}
int main()
{
	sito();
	scanf("%d%d",&c,&m);
	while(c--)
	{	scanf("%d",&n);
		//printf("%lld\n",dzielniki(pier+1));
		printf("%lld\n",dzielniki(pier+1)%m);
	};
return 0;
}