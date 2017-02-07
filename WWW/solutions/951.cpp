#include <cstdio>
#include <algorithm>
using namespace std;

unsigned int *t,t1,t2,t22;

inline unsigned int min(unsigned int a,unsigned int b)
{
	if(a<b)
		return a;
	return b;
}

unsigned int c(unsigned int i)
{
	if(i==2)
		return t2;
	if(i==3)
		return t1+t2+t[3];
	
	return min(c(i-2)+t1+t22+t[i],c(i-1)+t1+t[i]);
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
		t1=t[1];
		t2=t[2];
		t22=t[2]*2;
		printf("%u\n",c(n));
		delete [] t;
	}
	return 0;
}
