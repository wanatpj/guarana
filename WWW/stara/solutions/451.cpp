#include <cstdio>
using namespace std;

int main()
{
	int N,M,K,O,D;
	scanf ("%d %d",&N, &M);
	for (int i=1;i<=N;i++)
	{
		scanf ("%d %d %d",&K, &O, &D);
		if (M<K)
			printf ("komin\n");
		else if (M<O)
			printf ("okno\n");
		else if (M<D)
			printf ("drzwi\n");
		else printf ("brak\n");
	}
	return 0;
}
