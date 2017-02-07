//========================
//====Bartosz Miszczak====
//=======aTahualpa========
//========================
#include <iostream>
using namespace std;


int main()
{
ios_base::sync_with_stdio(0);

int z,n,wyn=0,tmp,tmp2,sum=0;
int tab[10001];

scanf("%d",&z);
for(int i=0;i<z;i++)
	{
	scanf("%d",&n);
	for(int j=0;j<n;j++)
		{ scanf("%d",&tab[j]); sum+=tab[j];}
	sort(tab,tab+n);
	sum-=tab[0];
	if(n%2==0)
		{
		tmp=(n>>1);
		wyn=tmp*tab[1]+(tmp-1)*tab[0]+(tmp-1)*tab[1];
		for(int j=n-1;j>2;j-=2)
			wyn+=tab[j];
		tmp2=sum+tmp*tab[0];
		if(tmp2<wyn) wyn=tmp2;
		}
	else
		{
		tmp=(n>>1);
		wyn=tmp*tab[1]+tmp*tab[0]+(tmp-1)*tab[1]+tab[2];
		for(int j=n-1;j>3;j-=2)
			wyn+=tab[j];
		tmp2=sum+tmp*tab[0];
		if(tmp2<wyn) wyn=tmp2;
		}

	printf("%d\n",wyn);
	wyn=0,sum=0;
	}




return 0;
}
