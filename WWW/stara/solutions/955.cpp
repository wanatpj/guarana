#include <cstdio>
#include <algorithm>
using namespace std;

unsigned int *t;

inline unsigned int min(unsigned int a,unsigned int b)
{
	if(a<b)
		return a;
	return b;
}

unsigned int c(unsigned int i)
{
	if(i==2)
		return t[2];
	if(i==3)
		return t[1]+t[2]+t[3];
	
	return min(c(i-2)+t[1]+2*t[2]+t[i],c(i-1)+t[i]+t[i]);
}

int main()
{
	unsigned int d,n;
	scanf("%u",&d);
	while(d--)
	{
		scanf("%u",&n);
		t=new unsigned int [n+1];
		for(unsigned int i=1;i<=n;++i)
			scanf("%u",t+i);
		sort(t+1,t+n+1);
		printf("%u\n",c(n));
		delete [] t;
	}
	return 0;
}
