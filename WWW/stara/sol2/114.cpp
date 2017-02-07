#include <iostream>

main()
{
	int n,m,k,rr,mm;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&k,&m);
		m-=k*505;
		rr=m%100;
		m/=100;
		mm=m%100;
		m/=100;
		printf("%.2d-%.2d-%.2d\n",m%100,mm,rr);
	}
	return 0;
}

