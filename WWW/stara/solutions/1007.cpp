#include <cstdio>
#include <algorithm>
#define MN 10009

using namespace std;

int n;
int C[MN];
int T[MN];

int main()
{
	int lw;
	scanf("%d",&lw);

	while (lw--)
	{
		scanf("%d",&n);

		for (int i=1;i<=n;i++)
			scanf("%d",&T[i]);

		sort(T+1,T+n+1);
		if (n>=1)
			C[1] = T[1];
		if (n>=2)
			C[2] = T[2];
		if (n>=3)
			C[3] = T[1]+T[2]+T[3];
		for (int i=4;i<=n;i++)
			C[i] = min( C[i-2] + T[1] + 2*T[2] + T[i], C[i-1] + T[1] + T[i] );
		printf("%d\n",C[n]);
	}

	return 0;
}

