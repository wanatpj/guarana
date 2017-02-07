#include <cstdio>
#include <algorithm>
using namespace std;

unsigned int *t,t1,t2,t22;
unsigned int *temp;

inline unsigned int min(unsigned int a,unsigned int b)
{
	if(a<b)
		return a;
	return b;
}

inline unsigned int c(unsigned int i)
{
	if(i==2)
		return t2;
	if(i==3)
		return t1+t2+t[3];
	
	if(temp[i]==0)
		temp[i]=min(c(i-2)+t1+t22+t[i],c(i-1)+t1+t[i]);
	
	return temp[i];
}

int main()
{
	unsigned int d,n;
	scanf("%u",&d);
	while(d--)
	{
		scanf("%u",&n);
		t=new unsigned int [n+1];
		temp=new unsigned int [n+1];
		for(unsigned int *begin=t+1,*end=t+n+1,*b2=temp+1;begin!=end;++begin,++b2)
		{
			scanf("%u",begin);
			*b2=0;
		}
		if(n==1)
		{
			printf("%u\n",t[1]);
			delete [] t;
			delete [] temp;
			continue;
		}
		sort(t+1,t+n+1);
		t1=t[1];
		t2=t[2];
		t22=t[2]*2;
		printf("%u\n",c(n));
		delete [] t;
		delete [] temp;
	}
	return 0;
}
