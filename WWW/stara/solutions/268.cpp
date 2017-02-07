#include <cstdio>
using namespace std;

int main()
{
	int n, pas;
	scanf ("%d %d", &n, &pas);
	for (int i = 0; i < n; i++)
	{
		int k, o, d;
		scanf ("%d %d %d", &k, &o, &d);
		if (pas < k)
			printf ("komin\n");
		else if (pas < o)
			printf ("okno\n");
		else if (pas < d)
			printf ("drzwi\n");
		else 
			printf ("brak\n");
	}
	return 0;
}

