#include <iostream>

int n;
int tmp;

long long res,maxi;

main()
{
	maxi=0;
	scanf("%d",&n);
	res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		res+=tmp;
		if(res<0) res=0;
		if(res>maxi) maxi=res;
	}
	printf("%lld",maxi);
}

