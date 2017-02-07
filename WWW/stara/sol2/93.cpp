#include <iostream>

int n;
int tmp;

long long res;

main()
{
	scanf("%d",&n);
	res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		res+=tmp;
		if(res<0) res=0;
	}
	printf("%lld",res);
}

