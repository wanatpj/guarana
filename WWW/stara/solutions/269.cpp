#include <cstdio>
using namespace std;

int main()
{
	int D;
	scanf ("%d", &D);
	while (D--)
	{
		int x = 0;
		int N;
		scanf ("%d", &N);
		while (N--)
		{
			int temp;
			scanf ("%d", &temp);
			x+=temp;
		}
		int C;
		scanf ("%d", &C);
		if (x > 0)
			printf ("%d\n", C%x);
		else
			printf ("%d\n", C);
	}
	return 0;
}

