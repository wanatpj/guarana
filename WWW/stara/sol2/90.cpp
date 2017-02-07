#include <iostream>

main()
{
	unsigned long long res=0; 
	int n;
	scanf("%d",&n);
	for(unsigned long long i=1;i<=n;i++)
	{
		if(i&1) res+=(i+1)/2*i;
		else res+=i/2*(i+1);
	}
	printf("%llu",res);
	return 0;
}

