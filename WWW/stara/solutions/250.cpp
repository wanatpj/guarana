#include <cstdio>

using namespace std;

int main()
{
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for(int i = 0;i<n;i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(m<a)
			printf("komin\n");
		else if(m<b)
			printf("okno\n");
		else if(m<c)
			printf("drzwi\n");
		else
			printf("brak\n");
	}
	return 0;
}
