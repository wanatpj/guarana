#include <iostream>
using namespace std;

main()
{
	bool re=0;
	long long n;
	scanf("%lld",&n);
	while(n)
	{
		if(n&1) re^=1;
		n>>=1;
	}
	printf("%d\n",re);
	return 0;
}

