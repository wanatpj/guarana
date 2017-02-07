#include <cstdio>

using namespace std;

int main()
{
	int n, m, u, v, il=0;
	scanf("%d %d", &n, &m);
	for(int i = 0;i<m;i++)
	{
		scanf("%*d %*d %*d %d %d", &u, &v);
		if(u==1 && v==0)
			il++;
	}
	printf("%d\n", il);
	return 0;
}
