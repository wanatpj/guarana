#include <cstdio>

int main()
{
	unsigned int d,n,s,t,m;
	bool q;
	scanf("%u",&d)
	while(d--)
	{
		scanf("%u",&n);
		s=m=0;
		q=n&1;
		while(n--)
		{
			scanf("%u",&t);
			t<m?t=m:false;
			s+=t;
		}
		if(q)
			s-=m;
		printf("%u\n",s);
	}
	return 0;
}
