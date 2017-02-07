#include <stdio.h>

int main(int argc, char* argv[])
{
	int d;
	scanf("%d", &d);
	while(d--)
	{
		int n, s=0, a;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &a);
			s += a;
		}
		scanf("%d", &a);
		printf("%d\n", s>0 ? a%s : a);
	}
	return 0;
}

