#include <cstdio>

using namespace std;

int main()
{
	int n, d, x, sum, c;
	scanf("%d", &d);
	while(d>0)
	{
		d--;
		scanf("%d", &n);
		sum=0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d", &x);
			sum+=x;
		}
		scanf("%d", &c);
		if(sum==0)
			printf("%d\n", c);
		else
			printf("%d\n", c%sum);
	}
	return 0;
}
