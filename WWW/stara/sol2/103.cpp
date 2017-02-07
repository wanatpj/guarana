#include <cstdio>

using namespace std;

#define LL long long 

LL max(LL a, LL b)
{
	if(a<b)
		return b;
	return a;
}

int main()
{
	int n;
	scanf("%d", &n);
	LL p=0, s=0, c, b=0;
	for(int i = 0;i<n;i++)
	{
		scanf("%lld", &c);
		s+=c;
		if(s-p<=0)
			p=s;
		b=max(b,s-p);
	}
	printf("%lld\n", b);
}
