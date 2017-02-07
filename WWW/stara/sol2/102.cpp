#include <cstdio>

using namespace std;

int max(int a, int b)
{
	if(a<b)
		return b;
	return a;
}

int main()
{
	int n;
	scanf("%d", &n);
	int p=0, s=0, c, b;
	b=0;
	for(int i = 0;i<n;i++)
	{
		scanf("%d", &c);
		s+=c;
		if(s-p<=0)
			p=s;
		b=max(b,s-p);
	}
	printf("%d\n", b);
}
