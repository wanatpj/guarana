#include <cstdio>

int main()
{
	unsigned int d,n,s,t,m,q;
	scanf("%u",&d);
	while(d--)
	{
		scanf("%u",&n);
		s=0;
		m=0xffffffff;
		q=n&1;
		while(n--)
		{
			scanf("%u",&t);
			t<m?m=t:false;
			s+=t;
		}
		if(q==0)
			s-=m;
		printf("%u\n",s);
	}
	return 0;
}
