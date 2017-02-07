#include <cstdio>

int main()
{
	int zw;
	scanf("%d", &zw);
	while(zw--)
	{
		int n;
		scanf("%d", &n);
		int os = 0;
		while(n--)
		{
			int a;
			scanf("%d", &a);
			os+=a;
		}
		int C;
		scanf("%d", &C);
		if(os!=0)
			C%=os;
		printf("%d\n", C);
	}

	return 0;
}