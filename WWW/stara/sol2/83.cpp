#include <iostream>
using namespace std;

main()
{
	bool re;
	long long n;
	scanf("%lld",&n);
	n--;
	if(n&1) re=0;
	else re=1;
	while(n)
	{
		if((n&1)==1) re^=1;
		n>>=1;
	}
	printf("%d\n",re);
	return 0;
}

